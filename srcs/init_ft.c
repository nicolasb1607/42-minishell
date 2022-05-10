/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:14:39 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/10 14:16:17 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtincmd(t_cmd *cmd)
{
	char	*currcont;

	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0)
		return (1);
	else if (!ft_strncmp(currcont, "exit", 5))
		return (1);
	else
		return (0);
}

int	is_forkbuiltin(t_cmd *cmd)
{
	char	*currcont;

	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0 && !cmd->options[1])
		return (1);
	else
		return (0);
}

char **ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	return (NULL);
}

t_cmd	*make_commands(t_tlist *tlst, t_cmd **chead, t_dlist **dupenv, t_tlist *curr)
{
	t_cmd	*cmd;
	char	**path;
	
	while (tlst)
	{
		curr = (tlst);
		cmd = tlst_to_cmd(&tlst);
		path = get_path_to_cmd(dupenv);
		if(update_bin(path, cmd, curr) == -1)
		{
			path = (ft_free_tab(path), free_tcmd(chead), free_tcmd(&cmd), NULL);
			if (g_mshell.err_exit != 130)
				g_mshell.err_exit = 127;
			return (NULL);
		}
		path = ft_free_tab(path);
		ft_clstadd_back(chead, cmd);
		if (tlst)
			(tlst) = (tlst)->next;
	}
	return (cmd);
}

void only1cmd(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	// char **path;
	t_cmd *cmd;
	pid_t pi;
	t_tlist *curr;
	t_pipes	pipes;
	int status;

	curr = tlst;
	if (tlst->token->content)
	{
		cmd = make_commands(tlst, &chead, dupenv, curr);
		if (!cmd)
			return ;
		open_io(chead, &pipes);
		// print_t_cmd(chead);
		if (ft_strcmp(chead->command,"./minishell") == 0)
			signal(SIGINT, SIG_IGN);
		else
			signal(SIGINT, handler_cmd);
		signal(SIGQUIT, SIG_IGN);
		if (is_builtincmd(cmd))
		{
			while (ft_strcmp(curr->token->content, cmd->command) != 0)
				curr = curr->next;
			if (is_forkbuiltin(cmd))
			{
				pi = fork();
				if (pi == 0)
				{
					dup2(pipes.fd_out, STDOUT_FILENO);
					dup2(pipes.fd_in, STDIN_FILENO);
					exec_builtin(curr, dupenv, &chead);
					free_tcmd(&cmd);
					exit(errno);
				}
			}
			else
				exec_builtin(curr, dupenv, &chead);
		}
		else if ((chead)->is_absolute)
		{
			pi = fork();
			if (pi == 0)
			{
				dup2(pipes.fd_out, STDOUT_FILENO);
				dup2(pipes.fd_in, STDIN_FILENO);
				if (execve((chead)->command, (chead)->options, dlist_to_tab(*dupenv)) != 0)
					exit(errno);
			}
		}
		else
		{
			pi = fork();
			if (pi == 0)
			{
				dup2(pipes.fd_out, STDOUT_FILENO);
				dup2(pipes.fd_in, STDIN_FILENO);
				if(execve((chead)->bin, (chead)->options, dlist_to_tab(*dupenv)) != 0)
					exit(errno);
			}
		}
		while(waitpid(pi, &status, 0) != -1)
		{
			if(WIFEXITED(status))
				g_mshell.err_exit = WEXITSTATUS(status);
		}
	}
	free_tcmd(&chead);
}

void	free_tcmd(t_cmd **cmd)
{
	t_cmd *curr;
	t_cmd *next;

	curr = *cmd;
	//print_t_cmd(curr);
	while (curr)
	{
		// dprintf(2, "freeing %s\n", curr->command);
		// if (curr->next)
			next = curr->next;
		free(curr->command);
		free(curr->bin);
		ft_free_tab(curr->infile);
		if(curr->limiter)
			curr->limiter = ft_free_tab(curr->limiter);
		free(curr->type);
		curr->options = ft_free_tab(curr->options);
		curr->outfile = ft_free_tab(curr->outfile);
		if (curr->builtin)
		{
			while (curr->builtin->prev)
				curr->builtin = curr->builtin->prev;
			while (curr->builtin)
			{
				free(curr->builtin);
				curr->builtin = curr->builtin->next;
			}
		}
		free(curr);
		curr = next;
	}
	*cmd = NULL;
	cmd = NULL;
}

int	is_builtin(t_tlist *lst)
{
	char	*currcont;

	currcont = lst->token->content;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(currcont, "exit", 5) == 0)
		return (1);
	else
		return (0);
}

void	cpy_till_pipe(t_tlist **tlist, t_tlist **tlistnew)
{
	t_tlist *curr;
	t_tlist *new;
	
	curr = *tlist;
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		new = ft_tlstnew(curr->token);
		ft_tlstadd_back(tlistnew, new);
		curr = curr->next;
	}
	*tlist = curr;
}

void	init_ft(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	char	**path;
	int		nb_cmd;
	t_cmd *cmd;
	t_tlist *curr;
	t_tlist	*tmp;

	nb_cmd = count_command(tlst);
	if (tlst->token->content)
	{
		while (tlst)
		{
			curr = tlst;
			if (!is_builtin(curr))
			{
				cmd = tlst_to_cmd(&tlst);
				path = get_path_to_cmd(dupenv);
				if (update_bin(path, cmd, curr) == -1)
				{
					path = (ft_free_tab(path), free_tcmd(&chead), free_tcmd(&cmd), NULL);
					if (g_mshell.err_exit != 130)
						g_mshell.err_exit = 127;
					return ;
				}
				ft_free_tab(path);
				cmd->is_builtin = false;
			}
			else
			{
				tmp = tlst;
				cmd = tlst_to_cmd(&tmp);
				tmp = tlst;
				cmd->builtin = NULL;
				cpy_till_pipe(&tlst, &cmd->builtin);
				// cmd->builtin = tlst;
				if (!cmd->infile)
				{
					cmd->infile = ft_tab_addback(cmd->infile, STDIN);
					cmd->update_i = false;
				}
				if (!cmd->outfile)
				{
					cmd->outfile = ft_tab_addback(cmd->outfile, STDOUT);
					cmd->update_o = false;
				}
			}
			if (tlst)
					tlst = tlst->next;
			ft_clstadd_back(&chead, cmd);
		}
		piping(nb_cmd, &chead, dupenv, tlst);
		free_tcmd(&chead);
		free_tlist(&tlst);
	}
}
// 72 24