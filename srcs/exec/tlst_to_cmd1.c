/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmdlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/02 10:30:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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

static void	update_io_firt_condition(t_cmd **cmd, t_tlist **lst)
{
	(*cmd)->outfile = ft_tab_addback((*cmd)->outfile, (*lst)->token->content);
	(*cmd)->is_double = false;
}

static void	update_io_scnd_condition(t_cmd **cmd,
	t_tlist **lst, char **file_name)
{
	(*file_name) = ft_strdup((*lst)->token->content);
	if ((*file_name)[ft_strlen((*file_name)) - 1] == ' ')
		(*file_name) = ft_strndup((*file_name), ft_strlen((*file_name)) - 1);
	if (!access((*file_name), F_OK))
		(*cmd)->infile = ft_tab_addback((*cmd)->infile, (*file_name));
	else
		ft_error("Cant open infile");
	(*cmd)->is_double = false;
	free((*file_name));
}

void	update_io(t_cmd *cmd, t_tlist *lst, int ret)
{
	char	*file_name;

	lst = lst->next;
	if (ret == 1)
		update_io_firt_condition(&cmd, &lst);
	else if (ret == 2)
		update_io_scnd_condition(&cmd, &lst, &file_name);
	else if (ret == 3)
	{
		file_name = ft_strdup(lst->token->content);
		cmd->outfile = ft_tab_addback(cmd->outfile, file_name);
		cmd->is_double = (free(file_name), true);
	}
	else if (ret == 4)
	{
		cmd->limiter = ft_tab_addback(cmd->limiter, lst->token->content);
		cmd->infile = ft_tab_addback(cmd->infile, create_tmp());
		cmd->is_double = true;
		make_heredoc(cmd);
	}
}
