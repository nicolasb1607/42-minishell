/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:26:11 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/12 10:35:14 by nburat-d         ###   ########.fr       */
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

static void make_heredoc_loop()
{
	while (i == 0)
		{
			tmp = readline("> ");
			if (!tmp)
			{
				ft_putstr(
					"minishell: warning: here-document at \
						line 1 delimited by end-of-file (wanted `hd')\n");
				break ;
			}
			if (tmp)
			{
				if (ft_strncmp(tmp, cmd->limiter[0],
						ft_strlen(cmd->limiter[0]) + 1) == 0)
					i = (1);
				else
				{
					write(fd, tmp, ft_strlen(tmp));
					write(fd, "\n", 1);
				}
			}
			else
				write(fd, "\n", 1);
			free(tmp);
		}
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
	{
		signal(SIGINT, handler_heredoc);
		while (i == 0)
		{
			tmp = readline("> ");
			if (!tmp)
			{
				ft_putstr(
					"minishell: warning: here-document at \
						line 1 delimited by end-of-file (wanted `hd')\n");
				break ;
			}
			if (tmp)
			{
				if (ft_strncmp(tmp, cmd->limiter[0],
						ft_strlen(cmd->limiter[0]) + 1) == 0)
					i = (1);
				else
				{
					write(fd, tmp, ft_strlen(tmp));
					write(fd, "\n", 1);
				}
			}
			else
				write(fd, "\n", 1);
			free(tmp);
		}
		exit (0);
	}
	exit_status_here_doc(pid);
	close(fd);
}
