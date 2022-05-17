/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:03 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/16 11:504 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	is_existing(char *varenv, t_dlist **dupenv)
{
	int		lentoequal;
	char	*content;
	t_dlist	*curr;

	curr = *dupenv;
	while (curr)
	{
		content = curr->content;
		lentoequal = 0;
		while (content[lentoequal] && content[lentoequal] != '=')
			lentoequal++;
		if (lentoequal < (int) ft_strlen(varenv))
			lentoequal = ft_strlen(varenv);
		if (ft_strncmp(content, varenv, lentoequal) == 0)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	ft_unset(char *varenv, t_dlist **dupenv)
{
	t_dlist	*curr;
	char	*content;


	curr = *dupenv;
	content = curr->content;
	if (is_existing(varenv, dupenv) == 0)
		return ;
	while (curr)
	{
		if (ft_strncmp(content, varenv, ft_strlen(varenv)) == 0)
		{
			ft_dlstdelone(curr, free, dupenv);
			return ;
		}
		curr = curr->next;
		content = curr->content;
	}
}

void	loop_unset(t_tlist *tlst, t_dlist **dupenv)
{
	t_tlist	*currtok;
	int		solo;

	solo = 0;
	currtok = tlst->next;
	if(!*dupenv)
		return ;
	if(ft_dlstsize(*dupenv) == 1)
		solo = 1;
	while (currtok)
	{
		ft_unset(currtok->token->content, dupenv);
		currtok = currtok->next;
	}
	if(solo == 1)
		*dupenv = NULL;
}
