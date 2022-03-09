/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:21:56 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 18:21:57 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_tlstadd_back(t_tlist **alst, t_tlist *new)
{
	t_tlist	*last;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (*alst != NULL && new != NULL)
	{
		last = ft_tlstlast(*alst);
		last->next = new;
		new->prev = last;
	}
}
