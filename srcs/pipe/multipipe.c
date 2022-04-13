/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:12:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/13 15:19:30 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	ft_norm(int status)
{
	(void)status;
	while (wait(NULL) != -1)
		;
}

void	close_pfd(int *pfd, int fd_in, t_cmd *cmd)
{
	dup2(fd_in, STDIN_FILENO);
	if (cmd->next)
		dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	close(fd_in);
}

void	close_child(int *pfd, int fd_in)
{
	dup2(pfd[0], fd_in);
	close(pfd[0]);
	close(pfd[1]);
}

// void	exec_builtin(t_cmd *cmd)
// {
// 	if (strcmp(cmd->builtin->token->content, echo) == 0)
// 		ft_echo(cmd->builtin);
// }

void	ft_child(int *pfd, t_cmd *cmd, t_pipes *data)
{
	close_pfd(pfd, cmd->fd_in, cmd);
	// if (cest 1 builtin)
	// 	exec_builtin(cmd);
	// else
	execve(cmd->bin, cmd->options, data->env);
}

void	ft_pipe(t_cmd *cmd, t_pipes *data)
{
	t_cmd	*tmp;
	int		pfd[2];
	pid_t	pid;
	int		status;
	
	tmp = cmd;
	while (tmp)
	{
		tmp->fd_in = data->fd_in;
		pipe(pfd);
		pid = fork();
		if (pid == 0)
			ft_child(pfd, tmp, data);
		close_child(pfd, data->fd_in);
		tmp = tmp->next;
	}
	waitpid(pid, &status, 0);
	ft_norm(status);
}
