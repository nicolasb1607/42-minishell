/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:29:04 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/09 15:27:33 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	pipe_creator(t_data *data)
{
	int	i;

	i = 0;
	data->pipe = malloc(sizeof(int *) * (data->nb_cmd - 1));
	if (data->pipe == NULL)
		ft_error("Allocation Error");
	while (i < (data->nb_cmd - 1))
	{
		data->pipe[i] = malloc(sizeof(int) * 2);
		if (data->pipe[i] == NULL)
			ft_error("Allocation Error");
		pipe(data->pipe[i]);
		i++;
	} 
}
