/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlst_to_cmdlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/03/28 15:46:56 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**get_path_to_cmd(t_tlist *tlst, t_dlist **dupenv)
{
	char	*path;
	t_dlist *curr;
	char	**splitpath;

	curr = *dupenv;
	path = NULL;
	(void)tlst;
	while (curr)
	{
		if (ft_strncmp(curr->content, "PATH=", 5) == 0)
		{
			path = ft_substr(curr->content, 5, ft_strlen(curr->content));
			if (!path)
				ft_error("Substr failed :(\n");
			ft_putendl_fd(path, 1);
			splitpath = ft_split(path, ':');
			free(path);
			return (splitpath);
		}
		curr = curr->next;
	}
	return (NULL);
}

void	update_bin(char **path, t_cmd *cmd)
{
	cmd->bin = get_bin(cmd->command, path);
}

t_cmd	*tlst_to_cmd(t_tlist *tlst)
{
	char	*opt;
	t_tlist *curr;
	t_cmd	*cmd;

	curr = tlst;
	opt = NULL;
	if (is_operator(curr->token->type) == 0)
	{
		cmd = ft_clstnew();
		cmd->command = ft_strdup(curr->token->content);
		printf("cmd.command =  %s\n", cmd->command);
		cmd->type = T_STRING;
		curr = curr->next;
	}
	while (curr)
	{
		if (is_operator(curr->token->type) == 0)
		{
			opt = ft_strjoin(opt, curr->token->content);
			opt = ft_strjoin(opt, " ");
		}
		else
			break ;
		curr = curr->next;
	}
	cmd->options = ft_split(opt, ' ');
	free(opt);
	return (cmd);
}
