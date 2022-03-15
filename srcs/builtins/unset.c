/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:03 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/15 12:12:12 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

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
		if(lentoequal < (int) ft_strlen(varenv))
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
			ft_dlstdelone(curr, free);
			return ;
		}
		curr = curr->next;
		content = curr->content;
	}
}
