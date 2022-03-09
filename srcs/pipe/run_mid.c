/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:29:12 by ngobert           #+#    #+#             */
/*   Updated: 2022/03/09 17:42:03 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	run_mid(t_data *data, int i)
{
	char	**paths;
	char	**cmd;
	char	*bin;

	data->child[i] = fork();
	if (data->child[i] < 0)
		ft_error("Forking error");
	else if (data->child[i] == 0)
	{
		cmd = ft_split(data->argv[i + 2], ' ');
		paths = get_paths(data);
		bin = get_bin(cmd[0], paths);
		close(data->pipe[i][0]);
		dup2(data->pipe[i - 1][0], STDIN_FILENO);
		dup2(data->pipe[i][1], STDOUT_FILENO);
		close(data->pipe[i - 1][0]);
		close(data->pipe[i][1]);
		execve(bin, cmd, data->envp);
	}
	else
	{
		close(data->pipe[i - 1][0]);
		close(data->pipe[i][1]);
	}
}
