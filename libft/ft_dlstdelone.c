/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:40 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/10 15:32:53 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_dlstdelone(t_dlist *lst, void (*del)(void*), t_dlist **dupenv)
{
	t_dlist	*tmp;
	t_dlist	*curr;

	tmp = lst;
	curr = lst;
	if (curr != NULL && del != NULL)
	{
		if (curr->prev == NULL && curr->next)
		{
			*dupenv = curr->next;
			curr->next->prev = NULL;
			free(curr->content);
			free(curr);
		}
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
		{
			curr->next->prev = tmp->prev;
			curr->prev->next = tmp->next;
			free(curr->content);
			free(curr);
		}
	}
}
