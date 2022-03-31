/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cust_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:22:37 by ngobert           #+#    #+#             */
/*   Updated: 2022/03/31 16:29:55 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_wordcount_custom(char *s, char c)
{
	int		i;
	int		word;
	int		count;
	char	quote;

	count = 0;
	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			quote = s[i++];
			count += (look_for_next_quote(s, quote, &i), 1);
		}
		else if (s[i] == c)
			word = 0;
		else if (word == 0)
		{
			if (s[i] != c && word == 0)
				word = (count++, 1);
		}
		i++;
	}
	return (count);
}

char	**ft_split_custom(char *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_wordcount_custom(s, c) + 1));
	if (!split)
		return (NULL);
	split = ft_cut_cu(s, split, c, i);
	return (split);
}

void	classicsplit(char *s, char **split, int *i, int *j)
{
	int	l;

	l = 0;
	split[*j] = malloc(sizeof(char) * ft_wordlen_cu(&s[*i], ' '));
	if (!split[*j])
	{
		free_tab_cu(split);
		return ;
	}
	while (s[*i] != ' ' && s[*i])
	{
		split[*j][l] = s[*i];
		*i = *i + 1;
		l++;
	}
	split[*j][l] = '\0';
}
