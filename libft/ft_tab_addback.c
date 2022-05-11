/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:50:50 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/11 11:18:59 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_tabz(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_tab_new(char *str)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 2);
	if (!tab)
		return (NULL);
	tab[0] = ft_strdup(str);
	tab[1] = NULL;
	return (tab);
}

char	**ft_tab_addback(char **tab, char *str)
{
	char	**new;
	int		i;

	i = 0;
	if (!tab)
		return (ft_tab_new(str));
	while (tab[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	ft_free_tabz(tab);
	return (new);
}
