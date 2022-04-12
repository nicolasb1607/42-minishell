/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:11:24 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/12 11:32:18 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	hd_child(t_pipes *pipes)
{
	if (pipes->here_doc == false)
		dup2(pipes->fd_in, STDIN_FILENO);
}

void	hd_parent(t_pipes *data)
{
	if (data->here_doc == false)
		close(data->fd_in);
}

void	first_cmd(t_cmd *cmd, t_pipes *pipes)
{
	pipes->child[0] = fork();
	if (pipes->child[0] == 0)
	{
		close(pipes->pipe[0][0]);
		hd_child(pipes);
		dup2(pipes->pipe[0][1], STDOUT_FILENO);
		if (pipes->here_doc == false)
			close(pipes->fd_in);
		close(pipes->pipe[0][1]);
		if (cmd->is_builtin == false)
			execve(cmd->bin, cmd->options, pipes->env);
		else
			exec_builtin(cmd, pipes);
	}
	else
	{
		hd_parent(pipes);
		close(pipes->pipe[0][1]);
	}
}