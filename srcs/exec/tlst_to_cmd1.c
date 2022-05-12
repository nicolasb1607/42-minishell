/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmdlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/02 10:30:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

#include "exec.h"

char	**tab_dup(char **tab)
{
	char	**new;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

t_cmd	*cpy_tcmd(t_cmd **cmd)
{
	t_cmd	*new;

	new = ft_clstnew();
	new->command = ft_strdup((*cmd)->command);
	new->options = tab_dup((*cmd)->options);
	new->bin = ft_strdup((*cmd)->bin);
	new->type = (*cmd)->type;
	ft_free_tab((*cmd)->options);
	free((*cmd));
	(*cmd) = NULL;
	return (new);
}

char	**get_path_to_cmd(t_dlist **dupenv)
{
	char	*path;
	t_dlist	*curr;
	char	**splitpath;

	curr = *dupenv;
	path = NULL;
	while (curr)
	{
		if (ft_strncmp(curr->content, "PATH=", 5) == 0)
		{
			path = ft_substr(curr->content, 5, ft_strlen(curr->content));
			if (!path)
				ft_error("Substr failed :(\n");
			splitpath = ft_split(path, ':');
			free(path);
			return (splitpath);
		}
		path = NULL;
		curr = curr->next;
	}
	return (NULL);
}

int	is_absolute(char *cmd)
{
	if (cmd)
	{
		if (cmd[0] == '/')
			return (1);
		else if (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/')
			return (1);
		else if (cmd[0] == '.' && cmd[1] == '/')
			return (1);
		else
			return (0);
	}
	return (-1);
}

int	update_bin(char **path, t_cmd *cmd, t_tlist *tlst)
{
	if (cmd->command && !is_builtincmd(cmd))
	{
		if (is_absolute(cmd->command) == 0)
		{
			cmd->bin = get_bin_custom(cmd->command, path, tlst);
			cmd->is_absolute = 0;
		}
		else
			cmd->is_absolute = 1;
	}
	else
		cmd->is_absolute = 1;
	if (!cmd->command || (!is_builtincmd(cmd)
		&& cmd->is_absolute == 0 && cmd->bin == NULL))
		return (-1);
	return (0);
}

char	*create_tmp(void)
{
	int		i;
	char	*str;

	i = INT_MIN;
	while (i < INT_MAX)
	{
		str = ft_itoa(i);
		str = ft_strjoin_free2("/tmp/.", str);
		if (access(str, F_OK) != 0)
			return (str);
		free(str);
		i++;
	}
	return (NULL);
}

void	make_heredoc(t_cmd *cmd, t_dlist **dupenv)
{
	pid_t	pid;
	char	*tmp;
	int		fd;
	int		i;
	int		status;

	i = 0;
	fd = open(cmd->infile[tab_size(cmd->infile) - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp = NULL;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, handler_heredoc);
		while (i == 0)
		{
			tmp = readline("> ");
			if (!tmp)
			{
				ft_putstr(
					"minishell: warning: here-document at line 1 delimited by end-of-file (wanted `hd')\n");
				break ;
			}
			if (tmp)
			{
				if (ft_strncmp(tmp, cmd->limiter[0], ft_strlen(cmd->limiter[0]) + 1) == 0)
					i = (1);
				else
				{
					write(fd, tmp, ft_strlen(tmp));
					write(fd, "\n", 1);
				}
			}
			else
				write(fd, "\n", 1);
			free(tmp);
		}
		execve("/bin/true", cmd->options, dlist_to_tab(*dupenv));
		exit (0);
	}
	while(waitpid(pid, &status, 0) != -1)
	{
			if(WIFEXITED(status))
				g_mshell.err_exit = WEXITSTATUS(status);
		}
	close(fd);
}

void	update_io(t_cmd *cmd, t_tlist *lst, int ret, t_dlist **dupenv)
{
	char	*file_name;
	
	lst = lst->next;
	if (ret == 1)
	{
		cmd->outfile = ft_tab_addback(cmd->outfile, lst->token->content);
		cmd->is_double = false;
	}
	else if (ret == 2)
	{
		file_name = ft_strdup(lst->token->content);
		if (file_name[ft_strlen(file_name) - 1] == ' ')
			file_name = ft_strndup(file_name, ft_strlen(file_name) - 1);
		if (!access(file_name, F_OK))
			cmd->infile = ft_tab_addback(cmd->infile, file_name);
		else
			ft_error("Cant open infile");
		cmd->is_double = false;
		free(file_name);
	}
	else if (ret == 3)
	{
		file_name = ft_strdup(lst->token->content);
		cmd->outfile = ft_tab_addback(cmd->outfile, file_name);
		cmd->is_double = (free(file_name), true);
	}
	else if (ret == 4)
	{
		file_name = create_tmp();
		cmd->limiter = ft_tab_addback(cmd->limiter, lst->token->content);
		cmd->infile = ft_tab_addback(cmd->infile, file_name);
		cmd->is_double = true;
		make_heredoc(cmd, dupenv);
		free(file_name);
	}
}

t_cmd	*tlst_to_cmd(t_tlist **tlst, t_dlist **dupenv)
{
	char	*opt;
	t_tlist *curr;
	t_cmd	*cmd;
	int		quote;
	int		i;

	quote = 0;
	i = 0;
	curr = *tlst;
	opt = NULL;
	cmd = ft_clstnew();
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		if (curr && is_operator(curr->token->type) == 0 && i == 0)
			cmd->command = (i++, ft_strdup(curr->token->content));
		while (curr && is_redir(curr->token->type) != 0)
		{
			update_io(cmd, curr, is_redir(curr->token->type), dupenv);
			if(g_mshell.err_exit == 130)
				break ;
			curr = curr->next->next;
		}
		if (curr && is_operator(curr->token->type) == 0)
		{
			if (i == 0)
				cmd->command = (i++, ft_strdup(curr->token->content));
			if (quote == 0 && curr->token->quote)
			{
				quote = 1;
				opt = ft_strjoin_free(opt, "\"");
			}
			opt = ft_strjoin_free(opt, curr->token->content);
			if (quote == 1)
			{
				quote = 0;
				opt = ft_strjoin_free(opt, "\"");
			}
			opt = ft_strjoin_free(opt, " ");
		}
		else
			break ;
		curr = curr->next;
	}
	*tlst = curr;
	cmd->options = ft_split_custom(opt, ' ');
	if (!cmd->infile)
	{
		cmd->infile = ft_tab_addback(cmd->infile, STDIN);
		cmd->update_i = false;
	}
	else
		cmd->update_i = true;
	if (!cmd->outfile)
	{
		cmd->outfile = ft_tab_addback(cmd->outfile, "/dev/stdout");
		cmd->update_o = false;
	}
	else
		cmd->update_o = true;
	free(opt);
	return (cmd);
}

void	exit_status_here_doc(int pid)
{
	int	status;

	while (waitpid(pid, &status, 0) != -1)
	{
		if (WIFEXITED(status))
			g_mshell.err_exit = WEXITSTATUS(status);
	}
}