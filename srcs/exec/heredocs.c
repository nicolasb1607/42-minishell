/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:26:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/12 10:56:14 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	exit_status_here_doc(int pid)
{
	int	status;

	while (waitpid(pid, &status, 0) != -1)
	{
		if (WIFEXITED(status))
			g_mshell.err_exit = WEXITSTATUS(status);
	}
}

static void	heredoc_rdline(int *fd, char **tmp, t_cmd **cmd, int *i)
{
	if (*tmp)
	{
		if (ft_strncmp(*tmp, (*cmd)->limiter[0],
				ft_strlen((*cmd)->limiter[0]) + 1) == 0)
			*i = (1);
		else
		{
			write(*fd, *tmp, ft_strlen(*tmp));
			write(*fd, "\n", 1);
		}
	}
	else
		write(*fd, "\n", 1);
}

static void	make_heredoc_loop(int *fd, char **tmp, t_cmd **cmd)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		*tmp = readline("> ");
		if (!*tmp)
		{
			ft_putstr(
				"minishell: warning: here-document at \
					line 1 delimited by end-of-file (wanted `hd')\n");
			break ;
		}
		heredoc_rdline(fd, tmp, cmd, &i);
		free(*tmp);
	}
}

void	make_heredoc(t_cmd *cmd)
{
	pid_t	pid;
	char	*tmp;
	int		fd;

	fd = open(cmd->infile[tab_size(cmd->infile) - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp = NULL;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, handler_heredoc);
		make_heredoc_loop(&fd, &tmp, &cmd);
		exit (0);
	}
	exit_status_here_doc(pid);
	close(fd);
}
