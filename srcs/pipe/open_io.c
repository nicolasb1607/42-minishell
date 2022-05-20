/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:52:33 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/20 11:23:06 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"
#include <string.h>

int	tab_size(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	open_i(t_cmd *cmd, t_pipes *pipes)
{
	int	fd;

	fd = open(cmd->infile[tab_size(cmd->infile) - 1], O_RDONLY);
	if (fd < 0)
		return (0);
	pipes->fd_in = fd;
	return (1);
}

char	*ft_strndup(char *str, int i)
{
	char	*new;
	int		j;

	j = 0;
	new = (char *)cmalloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		new[j] = str[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

int	open_o(t_cmd *cmd, t_pipes *pipes)
{
	int		fd;
	int		i;
	char	*file_name;

	i = 0;
	if (cmd->outfile[i])
	{
		while (cmd->outfile[i])
		{
			file_name = norm_open(&cmd, i);
			if (cmd->is_double == false || cmd->outfile[i + 1])
				fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			else if (cmd->is_double == true && !cmd->outfile[i + 1])
				fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
			if (cmd->outfile[i + 1])
				close(fd);
			else
				return (open_o_norm(&cmd, &pipes, file_name, fd));
			i += (free(file_name), 1);
		}
	}
	else
		return (open_o_norm2(&pipes));
	return (0);
}

int	open_io(t_cmd *cmd, t_pipes *pipes)
{
	int		i;
	int		o;
	t_cmd	*temp;

	temp = cmd;
	while (temp)
	{
		i = open_i(cmd, pipes);
		o = open_o(temp, pipes);
		temp = temp->next;
	}
	if (i == 0 || o == 0)
		return (0);
	return (1);
}
