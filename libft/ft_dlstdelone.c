/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:16:40 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/04 13:14:43 by nburat-d         ###   ########.fr       */
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
			printf("condition 1 \n");
			*dupenv = curr->next;
			curr->next->prev = NULL;
			free(curr->content);
			free(curr);
		}
		else if (!curr->next && !curr->prev)
		{
			printf("condition 2\n");
			free(curr->content);
			free(curr);
		}
		else if (curr->next == NULL && curr->prev)
		{
			printf("condition 3\n");
			curr->prev->next = NULL;
			free(curr->content);
			free(curr);
		}
		else
		{
			printf("condition 4\n");
			curr->next->prev = tmp->prev;
			curr->prev->next = tmp->next;
			free(curr->content);
			free(curr);
		}
	}
	printf("BABAYE\n");
}
