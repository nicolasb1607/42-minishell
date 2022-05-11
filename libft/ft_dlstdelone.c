/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:40 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 16:51:04 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_dlstdelone_condition1(t_dlist **dupenv, t_dlist **curr)
{
	*dupenv = (*curr)->next;
	(*curr)->next->prev = NULL;
	free((*curr)->content);
	free((*curr));
}

static void	ft_dlstdelone_condition2(t_dlist **curr, t_dlist **tmp)
{
	(*curr)->next->prev = (*tmp)->prev;
	(*curr)->prev->next = (*tmp)->next;
	free((*curr)->content);
	free((*curr));
}

void	ft_dlstdelone(t_dlist *lst, void (*del)(void*), t_dlist **dupenv)
{
	t_dlist	*tmp;
	t_dlist	*curr;

	tmp = lst;
	curr = lst;
	if (curr != NULL && del != NULL)
	{
		if (curr->prev == NULL && curr->next)
			ft_dlstdelone_condition1(dupenv, &curr);
		else if (!curr->next && !curr->prev)
		{
			free(curr->content);
			free(curr);
		}
		else if (curr->next == NULL && curr->prev)
		{
			curr->prev->next = NULL;
			free(curr->content);
			free(curr);
		}
		else
			ft_dlstdelone_condition2(&curr, &tmp);
	}
}
