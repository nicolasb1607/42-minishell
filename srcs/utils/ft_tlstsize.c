/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:21:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 18:21:51 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_tlstsize(t_tlist *lst)
{
	t_tlist	*current;
	int		size;

	current = lst;
	size = 0;
	while (current != NULL)
	{
		size++;
		printf("%d\n", size);
		current = current->next;
	}
	return (size);
}
