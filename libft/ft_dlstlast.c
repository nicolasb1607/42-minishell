/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:27:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/10 12:04:04 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Renvoie le dernier élément de la liste.

#1. Le début de la liste.*/
t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*current;

	if (lst == NULL)
		return (lst);
	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
