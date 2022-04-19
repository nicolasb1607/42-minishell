/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:12:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/19 16:13:15 by ngobert          ###   ########.fr       */
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
	if (!cmd->prev || (cmd->prev && cmd->prev->update_i == false))
		dup2(fd_in, STDIN_FILENO);
	else if (cmd->prev->update_i == true)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->next && cmd->update_o == false)
		dup2(pfd[1], STDOUT_FILENO);
	else if (cmd->next && cmd->update_o == true)
		dup2(cmd->fd_out, STDOUT_FILENO);
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

void	exec_builtin(t_tlist *builtin, t_dlist **denv)
{
	// dprintf(2, BRED"EXEC BUILTIN\n"CRESET);
	if (!ft_strncmp(builtin->token->content, "env", 3))
		ft_env(denv);
	else if (!ft_strncmp(builtin->token->content, "echo", 4))
		ft_echo(builtin);
	else if (!ft_strncmp(builtin->token->content, "cd", 2))
		launch_cd(builtin, denv);
	else if (!ft_strncmp(builtin->token->content, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(builtin->token->content, "unset", 5))
		loop_unset(builtin, denv);
	else if (!ft_strncmp(builtin->token->content, "export", 6))
		loop_export(builtin, denv);
}

void	check_io(t_cmd *cmd, t_pipes *data)
{
	int	fd_i;
	// int	fd_o;
	// int	size;

	(void)data;
	if (cmd->update_i)
	{
		close(0);
		fd_i = open(cmd->infile, O_RDONLY);
		dup2(fd_i, STDIN_FILENO);
		data->fd_in = fd_i;
	}
	if (cmd->update_o)
	{
		close(1);
		dup2(data->fd_out, STDOUT_FILENO);
		data->fd_out = cmd->fd_out;
	}
}

void	ft_child(int *pfd, t_cmd *cmd, t_pipes *data)
{
	check_io(cmd, data);
	close_pfd(pfd, cmd->fd_in, cmd);
	if (cmd->builtin)
	{
		exec_builtin(cmd->builtin, data->denv);
		exit(EXIT_SUCCESS);
	}
	else
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
		{
			ft_child(pfd, tmp, data);
		}
		close_child(pfd, data->fd_in);
		tmp = tmp->next;
	}
	waitpid(pid, &status, 0);
	ft_norm(status);
}
