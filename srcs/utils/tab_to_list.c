/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 18:22:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**list_to_tab(t_tlist *alst)
{
	char	**tmp;
	int		size;
	int		i;
	t_tlist	*curr;

	i = -1;
	curr = alst;
	size = ft_tlstsize(curr);
	tmp = malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		tmp[i] = ft_strdup(curr->token->content);
		curr = curr->next;
	}
	tmp[i] = ft_strdup("");
	return (tmp);
}
