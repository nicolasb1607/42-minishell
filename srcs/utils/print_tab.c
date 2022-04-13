/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:25:13 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/10 19:01:43 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab && tab[++i])
			printf("%s\n", tab[i]);
	}
}