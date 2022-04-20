/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:12:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/20 12:06:47 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	ft_norm(int *status)
{
	while (wait(status) != -1)
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
	if (!ft_strncmp(builtin->token->content, "env", 4))
		ft_env(denv);
	else if (!ft_strncmp(builtin->token->content, "echo", 5))
		ft_echo(builtin);
	else if (!ft_strncmp(builtin->token->content, "cd", 3))
		launch_cd(builtin, denv);
	else if (!ft_strncmp(builtin->token->content, "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(builtin->token->content, "unset", 6))
		loop_unset(builtin, denv);
	else if (!ft_strncmp(builtin->token->content, "export", 7))
		loop_export(builtin, denv);
	else if (!ft_strncmp(builtin->token->content, "exit", 5))
		ft_exit();
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
	{
		if(execve(cmd->bin, cmd->options, data->env) > 0)
			g_mshell.err_exit = errno;
	}

}

void	ft_pipe(t_cmd *cmd, t_pipes *data)
{
	t_cmd	*tmp;
	int		pfd[2];
	pid_t	pid;
	
	tmp = cmd;
	if (cmd->command && ft_strcmp(cmd->command, "./minishell") == 0)
		signal(SIGINT, SIG_IGN);
	else
		signal(SIGINT, handler_cmd);
	signal(SIGQUIT, SIG_IGN);
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
	waitpid(pid, &g_mshell.err_exit, 0);
	ft_norm(&g_mshell.err_exit);
}
