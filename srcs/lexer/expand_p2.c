/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:07:08 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/15 18:06:36 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	lenvarenv(char *str, int i)
{
	int	j;

	j = 1;
	i++;
	while (str[i] && ft_isenv(str[i]) == 1)
	{
		j++;
		i++;
	}
	return (j);
}

void	expandtok(t_token *token, t_minishell *mshell)
{
	int		i;
	char	*expandedstr;
	char	*ret_expand;

	i = 0;
	expandedstr = NULL;
	if (token->quote != NULL && ft_strncmp(token->quote, T_SQUOTE, 5) == 0)
		return ;
	while (token->content[i])
	{
		if (token->content[i] == '$' && ft_isenv(token->content[i + 1]) == 1)
		{
			ret_expand = expand(token, i, mshell);
			if (ret_expand)
				expandedstr = ft_strjoin(expandedstr, ret_expand);
			i = i + lenvarenv(token->content, i);
		}
		if (token->content[i])
			expandedstr = ft_charjoin(expandedstr, token->content[i]);
		i++;
	}
	token->content = expandedstr;
}
