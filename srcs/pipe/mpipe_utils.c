/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpipe_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:47 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/10 17:26:12 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	ft_norm(int *status)
{
	while (wait(status) != -1)
		;
}

void	close_child(int *pfd, int fd_in)
{
	dup2(pfd[0], fd_in);
	close(pfd[0]);
	close(pfd[1]);
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
