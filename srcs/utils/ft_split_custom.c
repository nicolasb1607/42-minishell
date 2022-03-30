/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:59:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/30 15:30:05 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_wordcount(char *s, char c)
{
	int	i;
	int	word;
	int	count;
	char quote;

	count = 0;
	word = 0;
	i = 0;
	while (s[i])
	{
		if( s[i] == '\"' || s[i] == '\'')
			{
				quote = s[i];
				look_for_next_quote(s, quote, &i);
				count++;
			}
		else if (s[i] == c)
			word = 0;
		else if (word == 0)
		{
			if (s[i] != c && word == 0)
			{
				word = 1;
				count++;
			}
		}
		i++;
	}
	return (count);
}

static int	ft_wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

static char	**free_tab(char **tab)
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


int	lenquote(char *str, int i, char q)
{
	int len;

	len = 0;
	while (str[i] != q)
	{
		len++;
		i++;
	}
	return (len);		
}

static char	**ft_cut(char *s, char **split, char c, int i)
{
	int		j;
	int		l;
	char	quote;
	int		len;

	j = -1;
	while (++j < ft_wordcount(s, c))
	{
		l = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\"' || s[i] == '\'')
		{
			quote = s[i++];
			len = lenquote(s, i, quote);
			split[j] = malloc(sizeof(char) * len + 1);
			if (!split[j])
				return (free_tab(split));
			while(i < len + i)
			{
				split[j][l] = s[i];
				i++;
				l++;
			}
			split[j][l] = '\0';
		}
		else if (s[i] != c)
		{
			split[j] = malloc(sizeof(char) * ft_wordlen(&s[i], c));
			if (!split[j])
				return (free_tab(split));
			while (s[i] != c && s[i])
			{
				split[j][l] = s[i];
				i++;
				l++;
			}
			split[j][l] = '\0';
		}
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
char	**ft_split_custom(char *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	split = ft_cut(s, split, c, i);
	return (split);
}
