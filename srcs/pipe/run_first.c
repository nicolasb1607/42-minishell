/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:30:38 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/23 13:09:09 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	here_doc_child(t_data *data)
{
	if (data->here_doc == false)
		dup2(data->infile, STDIN_FILENO);
}

void	here_doc_parent(t_data *data)
{
	if (data->here_doc == false)
		close(data->infile);
}

void	run_first(t_data *data)
{
	char	**paths;
	char	**cmd;
	char	*bin;
	
	data->child[0] = fork();
	if(data->child[0] < 0)
	{
		ft_error("Fork error");
	}
	else if (data->child[0] == 0)
	{
		cmd = (ft_split(data->argv[2], ' '));
		paths = get_paths(data);
		bin = get_bin(cmd[0], paths);
		close(data->pipe[0][0]);
		here_doc_child(data);
		dup2(data->pipe[0][1], STDOUT_FILENO);
		if (data->here_doc == false)
			close(data->infile);
		close(data->pipe[0][1]);
		execve(bin, cmd, data->envp);
	}
	else
	{
		here_doc_parent(data);
		close(data->pipe[0][1]);
	}
}
