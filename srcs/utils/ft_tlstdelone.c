/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:56:11 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/10 15:33:41 by ngobert          ###   ########.fr       */
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
			lst = curr->next;
			curr->next->prev = NULL;
			free(curr->token->content);
			free(curr);
		}
		else if (!curr->next && !curr->prev)
		{
			free(curr->token->content);
			free(curr);
		}
		else if (curr->next == NULL && curr->prev)
		{
			curr->prev->next = NULL;
			free(curr->token->content);
			free(curr);
		}
		else
		{
			curr->next->prev = tmp->prev;
			curr->prev->next = tmp->next;
			free(curr->token->content);
			free(curr);
		}
	}
}
