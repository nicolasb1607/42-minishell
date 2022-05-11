/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:38:12 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/11 10:39:01 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

int	open_o_norm(t_cmd **cmd, t_pipes **pipes, char *file_name, int fd)
{
	(*pipes)->fd_out = fd;
	(*cmd)->fd_out = fd;
	free(file_name);
	return (1);
}

int	open_o_norm2(t_pipes **pipes)
{
	(*pipes)->fd_out = 1;
	return (1);
}

char	*norm_open(t_cmd **cmd, int i)
{
	char	*file_name;

	if ((*cmd)->outfile[i][ft_strlen((*cmd)->outfile[i]) - 1] == ' ')
		file_name = ft_strndup((*cmd)->outfile[i],
				ft_strlen((*cmd)->outfile[i]) - 1);
	else
		file_name = ft_strdup((*cmd)->outfile[i]);
	return (file_name);
}
