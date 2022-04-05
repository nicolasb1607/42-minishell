/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:35:23 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/05 16:48:10 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_cmd	*ft_clstnew(void)
{	
	t_cmd *node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	return (node);
}

t_cmd	*ft_clstlast(t_cmd *lst)
{
	t_cmd	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_clstadd_back(t_cmd **alst, t_cmd *new)
{
	t_cmd	*last;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (*alst != NULL && new != NULL)
	{
		last = ft_clstlast(*alst);
		last->next = new;
		new->prev = last;
	}
}

int	is_operator(char *content)
{
	if (ft_strcmp(content, T_DL_DIR) == 0)
		return (1);
	else if (ft_strcmp(content, T_DR_DIR) == 0)
		return (1);
	else if (ft_strcmp(content, T_L_DIR) == 0)
		return (1);
	else if (ft_strcmp(content, T_R_DIR) == 0)
		return (1);
	else if (ft_strcmp(content, T_PIPE) == 0)
		return (1);
	else
		return (0);
}