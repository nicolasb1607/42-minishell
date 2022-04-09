/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:41 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/09 15:30:44 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	alloc_pipes(t_cmd *cmd, t_pipes *pipes)
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
	alloc_pipes(cmd, pipes);
}

void	piping(int nbcmd, t_cmd *cmd, char **envp)
{
	t_pipes	pipes;

	pipes.nb_cmd = nbcmd;
	pipes.env = envp;
	pipes.nb_pipe = nbcmd - 1;
	(void)envp;
	open_io(cmd);
	print_t_cmd(cmd);
	pipex(cmd, &pipes);
}