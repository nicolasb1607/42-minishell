/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/04 18:41:30 by ngobert          ###   ########.fr       */
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
		if (currtok->token->content)
		{
			next = currtok->next;
			free(currtok->token->content);
			free(currtok->token);
			free(currtok);
			currtok = next;
		}
	}
	*tlst = NULL;
}
