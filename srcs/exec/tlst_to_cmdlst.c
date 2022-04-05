/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlst_to_cmdlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/05 16:53:16 by ngobert          ###   ########.fr       */
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
			splitpath = ft_split(path, ':');
			free(path);
			return (splitpath);
		}
		curr = curr->next;
	}
	return (NULL);
}

int	is_absolute(char *cmd)
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

void	update_bin(char **path, t_cmd *cmd, t_tlist *tlst)
{
	if (is_absolute(cmd->command) == 0)
	{
		cmd->bin = get_bin_custom(cmd->command, path, tlst);
		cmd->is_absolute = 0;	
	}
	else
		cmd->is_absolute = 1;
}

t_cmd	*tlst_to_cmd(t_tlist **tlst)
{
	char	*opt;
	t_tlist *curr;
	t_cmd	*cmd;
	int		quote;

	quote = 0;
	curr = *tlst;
	opt = NULL;
	if (is_operator(curr->token->type) == 0)
	{
		cmd = ft_clstnew();
		cmd->command = ft_strdup(curr->token->content);
		cmd->type = T_STRING;
	}
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		if (is_operator(curr->token->type) == 0)
		{
			if (quote == 0 && curr->token->quote)
			{
				quote = 1;
				opt = ft_strjoin(opt, "\"");
			}
			opt = ft_strjoin(opt, curr->token->content);
			if (quote == 1)
			{
				quote = 0;
				opt = ft_strjoin(opt, "\"");
			}
			opt = ft_strjoin(opt, " ");
		}
		else
			break ;
		curr = curr->next;
	}
	*tlst = curr;
	cmd->options = ft_split_custom(opt, ' ');
	free(opt);
	return (cmd);
}
