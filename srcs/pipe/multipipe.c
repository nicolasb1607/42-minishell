/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:12:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/16 20:05:19 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	exec_builtin(t_tlist *builtin, t_dlist **denv, t_cmd **cmd)
{
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
		ft_exit(builtin, cmd);
}

void	check_io(t_cmd *cmd, t_pipes *data)
{
	(void)data;
	if (cmd->update_i)
	{
		close(0);
		dup2(cmd->fd_in, STDIN_FILENO);
		data->fd_in = cmd->fd_in;
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
		exec_builtin(cmd->builtin, data->denv, &cmd);
		execve("/bin/true", cmd->options, dlist_to_tab(*data->denv));
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (execve(cmd->bin, cmd->options, data->env) > 0)
			g_mshell.err_exit = errno;
	}
}

void	ft_pipe(t_cmd *cmd, t_pipes *data)
{
	t_cmd	*tmp;
	int		pfd[2];
	pid_t	pid;
	int		status;

	tmp = cmd;
	if (cmd->command && ft_strcmp(cmd->command, "./minishell") == 0)
		signal(SIGINT, SIG_IGN);
	else
		signal(SIGINT, handler_cmd);
	//signal(SIGQUIT, SIG_IGN);
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
	if (waitpid(pid, &status, 0) != -1)
		if (WIFEXITED(status))
			g_mshell.err_exit = WEXITSTATUS(status);
	ft_norm(&status);
}
