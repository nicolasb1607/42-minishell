/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:52:33 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/09 14:55:10 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

int	open_i(t_cmd *cmd)
{
	int	fd;

	fd = open(cmd->infile, O_RDONLY);
	if (fd < 0)
		return (0);
	cmd->fd_in = fd;
	return (1);
}

int	open_o(t_cmd *cmd)
{
	int	fd;
	int	i;

	i = 0;
	while (cmd->outfile[i])
	{
		if (cmd->is_double == false)
			fd = open(cmd->options[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (cmd->is_double == true)
			fd = open(cmd->options[i], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (cmd->outfile[i + 1])
			close(fd);
		else
		{
			cmd->fd_out = fd;
			return (1);
		}
		i++;
	}
	return (0);
}

int	open_io(t_cmd *cmd)
{
	int	i;
	int	o;

	i = open_i(cmd);
	o = open_o(cmd);
	if (i == 0 || o == 0)
		return (0);
	return (1);
}