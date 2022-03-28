/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlst_to_cmdlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/03/25 12:58:11 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_cmd	*ft_clstnew(char *cmd, char *type)
{	
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->command = cmd;
	node->type = type;
	node->options = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


int	not_operator(char *content)
{
	if (ft_strcmp(content, T_DL_DIR) == 0)
		return (0);
	else if (ft_strcmp(content, T_DR_DIR) == 0)
		return (0);
	else if (ft_strcmp(content, T_L_DIR) == 0)
		return (0);
	else if (ft_strcmp(content, T_R_DIR) == 0)
		return (0);
	else if (ft_strcmp(content, T_PIPE) == 0)
		return (0);
	else
		return (1);
}

t_cmd	*tlst_to_cmd(t_tlist *tlst)
{
	t_cmd	*cmd;

	while (tlst)
	{
		if (not_operator(tlst->token->content) == 1)
		{
			cmd = ft_clstnew(tlst->token->content, tlst->token->type);
		}
	}
}