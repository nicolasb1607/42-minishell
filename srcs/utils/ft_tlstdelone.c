/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:56:11 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/01 16:09:51 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_tlstdelone(t_tlist *lst, void (*del)(void*))
{
	t_tlist	*tmp;

	tmp = lst;
	if (lst != NULL && del != NULL)
	{
		if (lst->next)
			lst->next->prev = tmp->prev;
		if (lst->prev)
			lst->prev->next = tmp->next;
		(*del)(lst->token->content);
		free(lst);
	}
}
