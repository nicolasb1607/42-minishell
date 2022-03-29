/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:56:11 by ngobert           #+#    #+#             */
/*   Updated: 2022/03/29 11:58:02 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_tlstdelone(t_tlist *lst, void (*del)(void*))
{
	t_tlist	*tmp;

	tmp = lst;
	if (lst != NULL && del != NULL)
	{
		lst->next->prev = tmp->prev;
		lst->prev->next = tmp->next;
		(*del)(lst->token->content);
		free(lst);
	}
}
