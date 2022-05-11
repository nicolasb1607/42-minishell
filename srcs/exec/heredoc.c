/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:18:49 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 11:27:04 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*create_tmp(void)
{
	int		i;
	char	*str;

	i = INT_MIN;
	while (i < INT_MAX)
	{
		str = ft_itoa(i);
		str = ft_strjoin("/tmp/.", str);
		if (access(str, F_OK) != 0)
			return (str);
		free(str);
		i++;
	}
	return (NULL);
}

static void	exit_status_here_doc(int pid)
{
	int	status;

	while (waitpid(pid, &status, 0) != -1)
	{
		if (WIFEXITED(status))
			g_mshell.err_exit = WEXITSTATUS(status);
	}
}

static void	loop_make_heredoc(char **tmp, int *i, t_cmd **cmd, int *fd)
{
	if (*tmp)
	{
		if (ft_strncmp(*tmp, (*cmd)->limiter[0],
				ft_strlen((*cmd)->limiter[0]) + 1) == 0)
			*i = 1;
		else
		{
			write(*fd, *tmp, ft_strlen(*tmp));
			write(*fd, "\n", 1);
		}
	}
	else
		write(*fd, "\n", 1);
}

static void	child_here_doc(char **tmp, int *i, t_cmd **cmd, int *fd)
{
	signal(SIGINT, handler_heredoc);
	while (*i == 0)
	{
		*tmp = readline("> ");
		if (!*tmp)
		{
			ft_putstr("minishell: warning: here-document at \
				line 1 delimited by end-of-file (wanted `hd')\n");
			break ;
		}
		loop_make_heredoc(tmp, i, cmd, fd);
		free(*tmp);
	}
	exit(0);
}

void	make_heredoc(t_cmd *cmd)
{
	pid_t	pid;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(cmd->infile[tab_size(cmd->infile) - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp = NULL;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		child_here_doc(&tmp, &i, &cmd, &fd);
	exit_status_here_doc(pid);
	close(fd);
}
