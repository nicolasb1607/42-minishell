/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlst_to_cmd_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:27:27 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/16 11:58:32 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**tab_dup(char **tab)
{
	char	**new;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

t_cmd	*cpy_tcmd(t_cmd **cmd)
{
	t_cmd	*new;

	new = ft_clstnew();
	new->command = ft_strdup((*cmd)->command);
	new->options = tab_dup((*cmd)->options);
	new->bin = ft_strdup((*cmd)->bin);
	new->type = (*cmd)->type;
	ft_free_tab((*cmd)->options);
	free((*cmd));
	(*cmd) = NULL;
	return (new);
}

char	**get_path_to_cmd(t_dlist **dupenv)
{
	char	*path;
	t_dlist	*curr;
	char	**splitpath;

	curr = *dupenv;
	path = NULL;
	while (curr)
	{
		if (ft_strncmp(curr->content, "PATH=", 5) == 0)
		{
			path = ft_substr(curr->content, 5, ft_strlen(curr->content));
			if (!path)
				ft_error("Substr failed :(\n");
			splitpath = ft_split(path, ':');
			free(path);
			return (splitpath);
		}
		path = NULL;
		curr = curr->next;
	}
	return (NULL);
}

int	is_absolute(char *cmd)
{
	if (cmd)
	{
		if (cmd[0] == '/')
			return (1);
		else if (cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/')
			return (1);
		else if (cmd[0] == '.' && cmd[1] == '/')
			return (1);
		else
			return (0);
	}
	return (-1);
}

int	update_bin(char **path, t_cmd *cmd, t_tlist *tlst)
{
	if (cmd->command && !is_builtincmd(cmd))
	{
		if (is_absolute(cmd->command) == 0)
		{
			cmd->bin = get_bin_custom(cmd->command, path, tlst);
			cmd->is_absolute = 0;
		}
		else
			cmd->is_absolute = 1;
	}
	else
		cmd->is_absolute = 1;
	if (!cmd->command || (!is_builtincmd(cmd)
			&& cmd->is_absolute == 0 && cmd->bin == NULL))
		return (-1);
	return (0);
}
