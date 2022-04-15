/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:52:33 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/14 16:49:13 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

int	open_i(t_cmd *cmd, t_pipes *pipes)
{
	int	fd;

	fd = open(cmd->infile, O_RDONLY);
	if (fd < 0)
		return (0);
	pipes->fd_in = fd;
	return (1);
}

int	open_o(t_cmd *cmd, t_pipes *pipes)
{
	int	fd;
	int	i;

	i = 0;
	if (cmd->outfile)
	{
		while (cmd->outfile[i])
		{
			if (cmd->is_double == false)
				fd = open(cmd->outfile[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			else if (cmd->is_double == true)
				fd = open(cmd->outfile[i], O_CREAT | O_WRONLY | O_APPEND, 0644);
			if (cmd->outfile[i + 1])
				close(fd);
			else
			{
				pipes->fd_out = fd;
				return (1);
			}
			i++;
		}
	}
	else
	{
		pipes->fd_out = 1;
		return (1);
	}
	return (0);
}

int	open_io(t_cmd *cmd, t_pipes *pipes)
{
	int	i;
	int	o;

	i = open_i(cmd, pipes);
	o = open_o(cmd, pipes);
	if (i == 0 || o == 0)
		return (0);
	return (1);
}