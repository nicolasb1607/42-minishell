/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/24 10:46:53 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_tlist(t_tlist **tlst)
{
	t_tlist	*currtok;
	t_tlist	*next;

	currtok = *tlst;
	while (currtok)
	{
		next = currtok->next;
		free(currtok);
		currtok = next;
	}
	*tlst = NULL;
}
