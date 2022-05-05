/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:32:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/05 16:28:02 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"


void	free_till_pipe(t_tlist *tlst)
{
	int		i;
	t_tlist	*next;
	t_tlist	*curr;
	
	curr = tlst;
	i = 0;
	while (curr && curr->prev)
		curr = (i++, curr->prev);
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
			next = curr->next;
			if (curr->token->content)
			{
				if (ft_strlen(curr->token->content) != 0)
					free(curr->token->content);
				free(curr->token);
				free(curr);
				curr = next;
			}
	}
}

void free_tlist(t_tlist **tlst)
{
	t_tlist *currtok;
	t_tlist *next;

	currtok = *tlst;
	while (currtok)
	{
		if (currtok->token->content)
		{
			next = currtok->next;
			if (ft_strlen(currtok->token->content) != 0)
				free(currtok->token->content);
			free(currtok->token);
			free(currtok);
			currtok = next;
		}
	}
	*tlst = NULL;
}
