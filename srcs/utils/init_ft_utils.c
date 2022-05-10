/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:23:12 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/10 17:11:28 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_builtincmd(t_cmd *cmd)
{
	char	*currcont;

	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0)
		return (1);
	else if (!ft_strncmp(currcont, "exit", 5))
		return (1);
	else
		return (0);
}

int	is_forkbuiltin(t_cmd *cmd)
{
	char	*currcont;

	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0 && !cmd->options[1])
		return (1);
	else
		return (0);
}

void	cpy_till_pipe(t_tlist **tlist, t_tlist **tlistnew)
{
	t_tlist	*curr;
	t_tlist	*new;

	curr = *tlist;
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		new = ft_tlstnew(curr->token);
		ft_tlstadd_back(tlistnew, new);
		curr = curr->next;
	}
	*tlist = curr;
}

int	is_builtin(t_tlist *lst)
{
	char	*currcont;

	currcont = lst->token->content;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(currcont, "exit", 5) == 0)
		return (1);
	else
		return (0);
}
