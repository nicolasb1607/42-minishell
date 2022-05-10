/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:56:11 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/10 17:17:15 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	t_norm(t_tlist **curr, t_tlist **tmp)
{
	(*curr)->next->prev = (*tmp)->prev;
	(*curr)->prev->next = (*tmp)->next;
	free((*curr)->token->content);
	free((*curr));
}

void	ft_tlstdelone(t_tlist *lst, void (*del)(void*))
{
	t_tlist	*tmp;
	t_tlist	*curr;
	int		i;

	tmp = lst;
	curr = lst;
	if (curr != NULL && del != NULL)
	{
		if (curr->prev == NULL && curr->next)
		{
			lst = curr->next;
			curr->next->prev = NULL;
			i = (free(curr->token->content), free(curr), 0);
		}
		else if (!curr->next && !curr->prev)
			i = (free(curr->token->content), free(curr), 0);
		else if (curr->next == NULL && curr->prev)
		{
			curr->prev->next = (NULL);
			i = (free(curr->token->content), free(curr), 0);
		}
		else
			t_norm(&curr, &tmp);
	}
	i++;
}
