/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:39:24 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/13 09:57:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

#define NO_ACCESS "no such file or directory\n"

static void	maj_old_pwd(t_dlist **dupenv, char *curr_dir)
{
	char	*content;
	t_dlist	*curr;

	curr = *dupenv;
	content = curr->content;
	if (is_existing("OLDPWD", dupenv) == 0)
		return ;
	while (curr && ft_strncmp(content, "OLDPWD=", 7) != 0)
	{
		curr = curr->next;
		content = curr->content;
	}
	content = ft_strjoin("OLDPWD=", curr_dir);
	free(curr->content);
	curr->content = content;
}

void	save_olddir(t_dlist **dupenv)
{
	char	*curr_dir;

	curr_dir = NULL;
	curr_dir = getcwd(curr_dir, 2048);
	if (!curr_dir)
		return ;
	maj_old_pwd(dupenv, curr_dir);
	free(curr_dir);
}

void	*ft_cd(char *path_name, t_dlist **dupenv)
{
	char	*curr_dir;
	char	*content;
	t_dlist	*curr;

	curr = *dupenv;
	content = curr->content;
	curr_dir = (save_olddir(dupenv), NULL);
	if (chdir(path_name) == -1)
		return (ft_putstr(NO_ACCESS), NULL);
	if (is_existing("PWD", dupenv) == 0)
		return (NULL);
	curr_dir = getcwd(curr_dir, 2048);
	if (!curr_dir)
		return (NULL);
	while (curr && ft_strncmp(content, "PWD=", 4) != 0)
	{
		curr = curr->next;
		content = curr->content;
	}
	content = (free(curr->content), ft_strjoin("PWD=", curr_dir));
	curr->content = content;
	return (NULL);
}	

void	launch_cd(t_cmd *cmd, t_dlist **dupenv)
{
	if (!cmd->options)
		ft_cd(look_for_varenv_value("HOME", dupenv), dupenv);
	else
		ft_cd(cmd->options[1], dupenv);
}
