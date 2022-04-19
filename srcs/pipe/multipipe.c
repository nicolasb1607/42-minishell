/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:12:58 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/19 10:30:11 by nburat-d         ###   ########.fr       */
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

void	exec_builtin(t_tlist *builtin, t_dlist **denv)
{
	if (ft_strncmp(builtin->token->content, "echo ", 4) == 0)
			ft_echo(builtin);
		else if (ft_strncmp(builtin->token->content, "cd ", 2) == 0)
			launch_cd(builtin, denv);
		else if (ft_strncmp(builtin->token->content, "env ", 3) == 0)
			ft_env(denv);
		else if (ft_strncmp(builtin->token->content, "pwd ", 3) == 0)
			ft_pwd();
		else if (ft_strncmp(builtin->token->content, "unset ", 5) == 0)
			loop_unset(builtin, denv);
		else if (ft_strncmp(builtin->token->content, "export ", 6) == 0)
			loop_export(builtin, denv);
		else if (ft_strncmp(builtin->token->content, "exit ", 4) == 0)
			ft_exit();
		
}

void	ft_child(int *pfd, t_cmd *cmd, t_pipes *data)
{
	close_pfd(pfd, cmd->fd_in, cmd);
	if (cmd->builtin)
	{
		exec_builtin(cmd->builtin, data->denv);
		exit(0);
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
	signal(SIGQUIT, SIG_IGN);
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
	waitpid(pid, &g_mshell.err_exit, 0);
	ft_norm(&g_mshell.err_exit);
}
