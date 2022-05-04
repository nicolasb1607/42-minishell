/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:07:07 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/04 13:34:58 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

char	*get_bin_custom(char *cmd, char **paths, t_tlist *tlst)
{
	char	*tmp;
	char	*ret_path;
	int		i;
	int		j;

	// tmp = ft_strdup("");
	ret_path = NULL;
	i = -1;
	if (paths)
	{
		while (paths[++i])
		{
			j = -1;
			tmp = ft_strjoin(paths[i], "/");
			while (cmd[++j] != ' ' && cmd[j])
				tmp = ft_charjoin(tmp, cmd[j]);
			ret_path = ft_strdup(tmp);
			free(tmp);
			if (ft_containchar(' ', cmd) == 1 && tlst->token->quote)
				ret_path = (free(ret_path), ft_strdup(cmd));
			if (access(ret_path, F_OK) == 0)
				return (ret_path);
			free(ret_path);
		}
	}
	return (ft_error("Command not found\n"), NULL);
}

char	*get_bin(char *cmd, char **paths)
{
	char	*tmp;
	char	*ret_path;
	int		i;
	int		j;

	tmp = ft_strdup("");
	ret_path = NULL;
	i = -1;
	while (paths[++i])
	{
		j = -1;
		tmp = ft_strjoin(paths[i], "/");
		while (cmd[++j] != ' ' && cmd[j])
			tmp = ft_charjoin(tmp, cmd[j]);
		ret_path = ft_strdup(tmp);
		if (ft_containchar(' ', cmd) == 1)
			ret_path = (free(ret_path), ft_strdup(cmd));
		if (access(ret_path, F_OK) == 0)
			return (ret_path);
		free(ret_path);
	}
	return (ft_error("Command not found\n"), NULL);
}

char	*get_line(t_data *data)
{
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (data->envp[++i])
	{
		path = ft_strnstr(data->envp[i], "PATH=", ft_strlen(data->envp[i]));
		if (path && data->envp[i][0] == 'P' && data->envp[i][5] == '/')
		{
			path = ft_substr(path, 5, ft_strlen(path));
			if (!path)
				ft_error("Substr failed :(\n");
			return (path);
		}
	}
	return (NULL);
}

char	**get_paths(t_data *data)
{
	char	*str;
	char	**paths;

	str = get_line(data);
	paths = ft_split(str, ':');
	if (!paths)
		ft_error("Split failed\n");
	return (paths);
}
