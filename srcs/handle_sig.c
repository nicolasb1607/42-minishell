/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:54 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 15:52:34 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_sig.h"

void	free_dlist(t_dlist **dlist)
{
	t_dlist	*curr;
	t_dlist	*tmp;

	curr = *dlist;
	while (curr)
	{
		tmp = curr->next;
		free(curr->content);
		free(curr);
		curr = tmp;
	}
}
