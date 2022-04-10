/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:41 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/10 12:57:35 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	alloc_pipes(t_pipes *pipes)
{
	int	i;

	i = 0;
	pipes->pipe = malloc(sizeof(int *) * (pipes->nb_cmd - 1));
	if (!pipes->pipe)
		ft_error("Allocation error");
	while (i < (pipes->nb_cmd - 1))
	{
		pipes->pipe[i] = malloc(sizeof(int) * 2);
		if (!pipes->pipe[i])
			ft_error("Allocation Error");
		pipe(pipes->pipe[i]);
		i++;
	}
}

void	pipex(t_cmd *cmd, t_pipes *pipes)
{
	int	i;

	i = 1;
	alloc_pipes(pipes);
	first_cmd(cmd, pipes);
	cmd = cmd->next;
	while (i < pipes->nb_cmd - 1)
	{
		mid_cmd(cmd, pipes, i);
		cmd = cmd->next;
		i++;
	}
	last_cmd(cmd, pipes);
	cmd = cmd->next;
}

void	piping(int nbcmd, t_cmd *cmd, char **envp)
{
	t_pipes	pipes;

	pipes.here_doc = false; //! A changer plus tard pour quand on fera les here docs
	pipes.nb_cmd = nbcmd;
	pipes.env = envp;
	pipes.nb_pipe = nbcmd - 1;
	(void)envp;
	open_io(cmd, &pipes);
	print_t_cmd(cmd);
	pipex(cmd, &pipes);
}