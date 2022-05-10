/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:14:39 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/10 14:43:10 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd
	*make_commands(t_tlist *tlst, t_cmd **chead,
	t_dlist **dupenv, t_tlist *curr)
{
	t_cmd	*cmd;
	char	**path;

	while (tlst)
	{
		curr = (tlst);
		cmd = tlst_to_cmd(&tlst);
		path = get_path_to_cmd(curr, dupenv);
		if (update_bin(path, cmd, curr) == -1)
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

void	only1cmd(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	t_cmd	*cmd;
	pid_t	pi;
	t_tlist	*curr;
	t_pipes	pipes;
	int		status;

	curr = tlst;
	if (tlst->token->content)
	{
		cmd = make_commands(tlst, &chead, dupenv, curr);
		if (!cmd)
			return ;
		open_io(chead, &pipes);
		if (ft_strcmp(chead->command, "./minishell") == 0)
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

t_cmd	*mk_built(t_tlist **tlst)
{
	t_cmd	*cmd;
	t_tlist	*tmp;

	tmp = (*tlst);
	cmd = tlst_to_cmd(&tmp);
	tmp = (*tlst);
	cmd->builtin = NULL;
	cpy_till_pipe(tlst, &cmd->builtin);
	return (cmd);
}

t_cmd
	*mk_cmd_b(t_tlist **tlst, t_dlist **dupenv, t_cmd *chead, t_tlist **curr)
{
	t_cmd	*cmd;
	char	**path;

	cmd = tlst_to_cmd(tlst);
	path = get_path_to_cmd(*curr, dupenv);
	if (update_bin(path, cmd, *curr) == -1)
	{
		path = (ft_free_tab(path), free_tcmd(&chead), free_tcmd(&cmd), NULL);
		if (g_mshell.err_exit != 130)
			g_mshell.err_exit = 127;
		return (NULL);
	}
	cmd->is_builtin = (ft_free_tab(path), false);
	return (cmd);
}

void	init_ft(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	int		nb_cmd;
	t_cmd	*cmd;
	t_tlist	*curr;

	nb_cmd = count_command(tlst);
	if (tlst->token->content)
	{
		while (tlst)
		{
			curr = tlst;
			if (!is_builtin(curr))
			{
				cmd = mk_cmd_b(&tlst, dupenv, chead, &curr);
				if (!cmd)
					return ;
			}
			else
				cmd = mk_built(&tlst);
			if (tlst)
					tlst = tlst->next;
			ft_clstadd_back(&chead, cmd);
		}
		piping(nb_cmd, &chead, dupenv, tlst);
		nb_cmd = (free_tcmd(&chead), free_tlist(&tlst), nb_cmd);
	}
}
