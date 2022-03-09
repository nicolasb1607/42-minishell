/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:21:45 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 18:21:46 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_tlist	*ft_tlstlast(t_tlist *lst)
{
	t_tlist	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
