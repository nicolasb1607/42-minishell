/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlst_to_cmdlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/22 11:31:28 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// new->bin = ft_strdup((*cmd)->bin);
	new->command = ft_strdup((*cmd)->command);
	new->options = tab_dup((*cmd)->options);
	new->bin = 	ft_strdup((*cmd)->bin);
	new->type = (*cmd)->type;
	ft_free_tab((*cmd)->options);
	free((*cmd));
	(*cmd) = NULL;
	return (new);
}

char	**get_path_to_cmd(t_tlist *tlst, t_dlist **dupenv)
{
	char	*path;
	t_dlist *curr;
	char	**splitpath;

	curr = *dupenv;
	path = NULL;
	(void)tlst;
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
	if (!is_builtincmd(cmd))
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
	if (!is_builtincmd(cmd)&& cmd->is_absolute == 0 && cmd->bin == NULL)
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
		if (access(str, F_OK) != 0)
			return (str);
		free(str);
		i++;
	}
	return (NULL);
}

void	update_io(t_cmd *cmd, t_tlist *lst, int ret)
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
			cmd->infile = ft_strdup(file_name);
		else
			ft_error("Cant open infile");
		cmd->is_double = false;
	}
	else if (ret == 3)
	{
		cmd->outfile = ft_tab_addback(cmd->outfile, ft_strdup(lst->token->content));
		cmd->is_double = true;
	}
	else if (ret == 4)
	{
		cmd->limiter = ft_strdup(lst->token->content);
		cmd->infile = create_tmp();
		cmd->is_double = true;
	}
}

t_cmd	*tlst_to_cmd(t_tlist **tlst)
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
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->type = T_STRING;
	cmd->next = NULL;
	cmd->prev = NULL;
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		if (curr && is_operator(curr->token->type) == 0 && i == 0)
			cmd->command = (i++, ft_strdup(curr->token->content));
		while (curr && is_redir(curr->token->type) != 0)
		{
			update_io(cmd, curr, is_redir(curr->token->type));
			curr = curr->next->next;
		}
		if (curr && is_operator(curr->token->type) == 0)
		{
			if (i == 0)
				cmd->command = (i++, ft_strdup(curr->token->content));
			if (quote == 0 && curr->token->quote)
			{
				quote = 1;
				opt = ft_strjoin(opt, "\"");
			}
			opt = ft_strjoin(opt, curr->token->content);
			if (quote == 1)
			{
				quote = 0;
				opt = ft_strjoin(opt, "\"");
			}
			opt = ft_strjoin(opt, " ");
		}
		else
			break ;
		curr = curr->next;
	}
	*tlst = curr;
	cmd->options = ft_split_custom(opt, ' ');
	if (!cmd->infile)
	{
		cmd->infile = STDIN;
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
