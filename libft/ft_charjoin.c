/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:01:53 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/20 11:21:19 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*char_to_str(char c)
{
	char	*str;

	str = cmalloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_charjoin(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!c)
		return (NULL);
	if (str == NULL)
		return (char_to_str(c));
	new = cmalloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (free(str), NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	new[i] = c;
	new[i + 1] = '\0';
	return (new);
}
