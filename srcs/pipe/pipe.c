/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:29:04 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/20 11:23:12 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	pipe_creator(t_data *data)
{
	int	i;

	i = 0;
	data->pipe = cmalloc(sizeof(int *) * (data->nb_cmd - 1));
	if (data->pipe == NULL)
		ft_error("minishell: memory allocation error\n");
	while (i < (data->nb_cmd - 1))
	{
		data->pipe[i] = cmalloc(sizeof(int) * 2);
		if (data->pipe[i] == NULL)
			ft_error("minishell: memory allocation error\n");
		pipe(data->pipe[i]);
		i++;
	}
}
