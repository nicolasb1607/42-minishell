/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:56:06 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/23 13:09:11 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	run_last(t_data *data)
{
	char	**paths;
	char	**cmd;
	char	*bin;
	
	cmd = ft_split(data->argv[data->argc - 2], ' ');
	paths = get_paths(data);
	bin = get_bin(cmd[0], paths);
	data->nb_pipe = data->nb_cmd - 1;
	data->child[data->nb_cmd - 1] = fork();
	if (data->child[data->nb_cmd - 1] == 0)
	{
		close(data->pipe[data->nb_pipe - 1][1]);
		dup2(data->pipe[data->nb_pipe - 1][0], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
		close(data->pipe[data->nb_pipe - 1][0]);
		close(data->outfile);
		execve(bin, cmd, data->envp);
	}
	else
	{
		close(data->outfile);
		close(data->pipe[data->nb_pipe - 1][0]);
	}
}
