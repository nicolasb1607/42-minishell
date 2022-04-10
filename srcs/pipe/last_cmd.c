/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:38:54 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/10 12:59:12 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	last_cmd(t_cmd *cmd, t_pipes *pipes)
{
	pipes->child[pipes->nb_cmd - 1] = fork();
	if (pipes->child[pipes->nb_cmd - 1] == 0)
	{
		close(pipes->pipe[pipes->nb_pipe - 1][1]);
		dup2(pipes->pipe[pipes->nb_pipe - 1][0], STDIN_FILENO);
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(pipes->pipe[pipes->nb_pipe - 1][0]);
		close(pipes->fd_out);
		execve(cmd->bin, cmd->options, pipes->env);
	}
	else
	{
		close(pipes->fd_out);
		close(pipes->pipe[pipes->nb_pipe - 1][0]);
	}
}
