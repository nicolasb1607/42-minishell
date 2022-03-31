/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:59:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/31 16:29:48 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_wordlen_cu(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

char	**free_tab_cu(char **tab)
{
	int	i;

	i = 0;
	while (!tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	lenquote_cu(char *str, int i, char q)
{
	int	len;

	len = 0;
	while (str[i] != q && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	splitquotted(char **split, char *s, int *j, int *i)
{
	int		l;
	char	quote;
	int		len;

	l = 0;
	quote = s[*i];
	*i = *i + 1;
	len = lenquote_cu(s, *i, quote);
	split[*j] = malloc(sizeof(char) * len + 1);
	if (!split[*j])
	{
		free_tab_cu(split);
		return ;
	}
	len += *i;
	while (*i < len)
	{
		split[*j][l] = s[*i];
		*i = *i + 1;
		l++;
	}
	split[*j][l] = '\0';
}

char	**ft_cut_cu(char *s, char **split, char c, int i)
{
	int	j;

	j = -1;
	while (++j < ft_wordcount_custom(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\"' || s[i] == '\'')
			splitquotted(split, s, &j, &i);
		else if (s[i] != c)
			classicsplit(s, split, &i, &j);
	}
	split[j] = 0;
	return (split);
}

/*Alloue (avec malloc(3)) et retourne un tableau
de chaines de caracteres obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL.

Le tableau de nouvelles chaines de caractères,
résultant du découpage. NULL si l’allocation
échoue.

#1. La chaine de caractères à découper.
#2. Le caractère délimitant.*/
