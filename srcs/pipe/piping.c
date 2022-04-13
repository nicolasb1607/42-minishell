/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:41 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/12 11:44:30 by ngobert          ###   ########.fr       */
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

void	wait_to_end(t_pipes *pipes)
{
	int	i;
	int	status;

	i = 0;
	while (i < pipes->nb_cmd + 5)
	{
		waitpid(pipes->child[i], &status, 0);
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
	wait_to_end(pipes);
}

void	piping(int nbcmd, t_cmd *cmd, t_dlist **envp, t_tlist *lst)
{
	t_pipes	pipes;

	pipes.here_doc = false; //! A changer plus tard pour quand on fera les here docs
	pipes.tlst = lst;
	pipes.nb_cmd = nbcmd;
	pipes.env = dlist_to_tab(*envp);
	pipes.nb_pipe = nbcmd - 1;
	(void)envp;
	open_io(cmd, &pipes);
	// print_t_cmd(cmd);
	pipex(cmd, &pipes);
}