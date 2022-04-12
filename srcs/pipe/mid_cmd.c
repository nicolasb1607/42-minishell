/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:39:03 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/12 13:44:25 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	mid_cmd(t_cmd *cmd, t_pipes *pipes, int i)
{
	pipes->child[i] = fork();
	if (pipes->child[i] == 0)
	{
		close(pipes->pipe[i][0]);
		dup2(pipes->pipe[i - 1][0], STDIN_FILENO);
		dup2(pipes->pipe[i][1], STDOUT_FILENO);
		close(pipes->pipe[i - 1][0]);
		close(pipes->pipe[i][1]);
		if (cmd->is_builtin == false)
			execve(cmd->bin, cmd->options, pipes->env);
		else
			exec_builtin(cmd, pipes);
	}
	else
	{
		close(pipes->pipe[i - 1][0]);
		close(pipes->pipe[i][1]);
	}
}
// fd mal closed ?
