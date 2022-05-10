/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:54 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/10 17:13:35 by ngobert          ###   ########.fr       */
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
