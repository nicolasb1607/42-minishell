/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:56:11 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/04 14:52:10 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_tlstdelone(t_tlist *lst, void (*del)(void*))
{
	t_tlist	*tmp;
	t_tlist	*curr;

	tmp = lst;
	curr = lst;
	if (curr != NULL && del != NULL)
	{
		if (curr->prev == NULL && curr->next)
		{
			printf("condition 1 \n");
			lst = curr->next;
			curr->next->prev = NULL;
			free(curr->token->content);
			free(curr);
		}
		else if (!curr->next && !curr->prev)
		{
			printf("condition 2\n");
			free(curr->token->content);
			free(curr);
		}
		else if (curr->next == NULL && curr->prev)
		{
			printf("condition 3\n");
			curr->prev->next = NULL;
			free(curr->token->content);
			free(curr);
		}
		else
		{
			printf("condition 4\n");
			curr->next->prev = tmp->prev;
			curr->prev->next = tmp->next;
			free(curr->token->content);
			free(curr);
		}
	}
	printf("BABAYE\n");
}
