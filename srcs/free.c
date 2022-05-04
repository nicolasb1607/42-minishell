/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/04 11:08:43 by nburat-d         ###   ########.fr       */
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
			if(currtok->token->content && ft_strlen(currtok->token->content) != 0)
				free(currtok->token->content);
			free(currtok->token);
			free(currtok);
			currtok = next;
		}
	}
	*tlst = NULL;
}
