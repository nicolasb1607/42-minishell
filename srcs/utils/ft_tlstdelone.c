/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:56:11 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/19 13:37:04 by nburat-d         ###   ########.fr       */
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

void	ft_tlstdelone_cond(t_tlist **curr, int *solo,
		t_tlist **tmp, t_tlist **lst)
{
	int	i;

	if ((*curr)->prev == NULL && (*curr)->next)
	{
		*lst = (*curr)->next;
		(*curr)->next->prev = NULL;
		i = (free((*curr)->token->content), free((*curr)), 0);
	}
	else if (!(*curr)->next && !(*curr)->prev)
	{
		i = (free((*curr)->token->content), free((*curr)), 0);
		if (*solo == 1)
			*lst = NULL;
	}
	else if ((*curr)->next == NULL && (*curr)->prev)
	{
		(*curr)->prev->next = (NULL);
		i = (free((*curr)->token->content), free((*curr)), 0);
	}
	else
		t_norm(curr, tmp);
	i++;
}

void	ft_tlstdelone(t_tlist *curr, void (*del)(void*), t_tlist **lst)
{
	t_tlist	*tmp;
	int		solo;

	solo = 0;
	if (ft_tlstsize(*lst) == 1)
		solo = 1;
	tmp = *lst;
	if (curr != NULL && del != NULL)
		ft_tlstdelone_cond(&curr, &solo, &tmp, lst);
}
