/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:44:46 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/04 21:54:09 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	ft_sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	print_declared_var(t_dlist **dup_env)
{
	char	**tab;
	char	*temp;
	int		i;

	i = 0;
	tab = dlist_to_tab(*dup_env);
	ft_sort_tab(tab);
	while (tab[i])
	{
		temp = ft_strdup(tab[i]);
		free(tab[i]);
		tab[i] = ft_strjoin("export ", temp);
		free(temp);
		i++;
	}
	print_tab(tab);
	ft_free_tab(tab);
}
