/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/20 11:23:36 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**tlist_to_tab(t_tlist *alst)
{
	char	**tmp;
	int		size;
	int		i;
	t_tlist	*curr;

	i = -1;
	curr = alst;
	size = ft_tlstsize(curr);
	tmp = cmalloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		tmp[i] = ft_strdup(curr->token->content);
		curr = curr->next;
	}
	tmp[i] = ft_strdup("");
	return (tmp);
}

char	**dlist_to_tab(t_dlist *alst)
{
	char	**tmp;
	int		size;
	int		i;
	t_dlist	*curr;

	i = -1;
	curr = alst;
	size = ft_dlstsize(curr);
	tmp = malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		tmp[i] = ft_strdup(curr->content);
		curr = curr->next;
	}
	tmp[i] = NULL;
	return (tmp);
}
