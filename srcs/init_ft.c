/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:14:39 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/19 13:57:37 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	fork_absolute(t_pipes pipes, t_cmd *chead, t_dlist **dupenv)
{
	pid_t	pi;
	char	**tab;

	pi = fork();
	if (pi == 0)
	{
		tab = dlist_to_tab(*dupenv);
		dup2(pipes.fd_out, STDOUT_FILENO);
		dup2(pipes.fd_in, STDIN_FILENO);
		if (access(chead->command, F_OK) == 0)
		{
			if (execve((chead)->command,
					(chead)->options, tab) != 0)
				pi = pi;
		}
		else
		{
			ft_putendl_fd(RED"Command not found\n"CRESET, 2);
			ft_free_tab(tab);
			exit(127);
		}
	}
	return (pi);
}

pid_t	fork_normal(t_pipes pipes, t_cmd *chead, t_dlist **dupenv)
{
	pid_t	pi;

	pi = fork();
	if (pi == 0)
	{
		dup2(pipes.fd_out, STDOUT_FILENO);
		dup2(pipes.fd_in, STDIN_FILENO);
		if (execve((chead)->bin, (chead)->options, dlist_to_tab(*dupenv)) != 0)
			exit(errno);
	}
	return (pi);
}

pid_t	fork_built(t_tlist *curr, t_cmd *cmd, t_pipes pipes, t_dlist **dupenv)
{
	pid_t	pi;

	while (ft_strcmp(curr->token->content, cmd->command) != 0)
		curr = curr->next;
	if (is_forkbuiltin(cmd))
	{
		pi = fork();
		if (pi == 0)
		{
			dup2(pipes.fd_out, STDOUT_FILENO);
			dup2(pipes.fd_in, STDIN_FILENO);
			exec_builtin(curr, dupenv, &cmd);
			free_tlist(&curr);
			free_dlist(dupenv);
			free_tcmd(&cmd);
			exit(errno);
		}
	}
	else
		exec_builtin(curr, dupenv, &cmd);
	return (pi);
}

void	only1cmd(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	t_cmd	*cmd;
	pid_t	pi;
	t_tlist	*curr;
	t_pipes	pipes;

	curr = tlst;
	if (tlst->token->content)
	{
		cmd = make_commands(tlst, &chead, dupenv, curr);
		if (!cmd)
			return ;
		sig_norm(&pipes, &chead);
		if (is_builtincmd(cmd))
			pi = fork_built(curr, cmd, pipes, dupenv);
		else if ((chead)->is_absolute)
			pi = fork_absolute(pipes, chead, dupenv);
		else
			pi = fork_normal(pipes, chead, dupenv);
		exit_status_here_doc(pi);
	}
	free_tcmd(&chead);
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
				cmd = mk_built(&tlst, dupenv);
			if (tlst)
				tlst = tlst->next;
			ft_clstadd_back(&chead, cmd);
		}
		piping(nb_cmd, &chead, dupenv, tlst);
		nb_cmd = (free_tcmd(&chead), free_tlist(&tlst), nb_cmd);
	}
}
