/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:09 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 18:24:09 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	ft_echo(int ac, char **argv)
{
	int	i;
	int	trlnl;
	int	len;

	i = 1;
	trlnl = 0;
	if (ft_strcmp(argv[1], "-n") == 0)
	{
		trlnl = 1;
		i++;
	}
	printf("i = %d\n", i);
	while (i < ac)
	{
		ft_putstr(argv[i]);
		if (i == (ac - 1) && trlnl == 1)
		{
			len = ft_strlen(argv[i]);
			if (ft_strcmp(&argv[i][len - 1], "\n") != 0)
				ft_putchar('%');
		}
		i++;
	}
	ft_putchar('\n');
}
