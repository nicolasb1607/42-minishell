/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:07:08 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/23 14:32:40 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	lenvarenv(char *str, int i)
{
	int	j;

	j = 1;
	i++;
	if (str[i] == '?')
		return (2);
	while (str[i] && ft_isenv(str[i]) == 1)
	{
		j++;
		i++;
	}
	return (j);
}

static void	expandtok_condition2(t_token **token, char **expandedstr, int *i)
{
	if ((*token)->content[*i] == '$' && (!(*token)->content[*i + 1]
			|| (*token)->content[*i + 1] == '\"'
			|| (*token)->content[*i + 1] == '$'
			|| (*token)->content[*i + 1] == ' '))
	{
		(*expandedstr) = ft_charjoin((*expandedstr), (*token)->content[*i]);
		*i = *i + 1;
	}
}

static void	expandtok_condition1(t_token **token, char **expandedstr,
	char **ret_expand, t_minishell **mshell)
{
	int	i;

	i = 0;
	while ((*token)->content[i])
	{
		expandtok_condition2(token, expandedstr, &i);
		if ((*token)->content[i] == '$'
			&& (ft_isenv((*token)->content[i + 1]) == 1
				|| (*token)->content[i + 1] == '?'))
		{
			(*ret_expand) = expand((*token), i, *mshell);
			if ((*ret_expand))
				(*expandedstr) = ft_strjoin_free((*expandedstr), (*ret_expand));
			i = (free((*ret_expand)), i + lenvarenv((*token)->content, i));
		}
		else if ((*token)->content[i] == '$')
			i++;
		if ((*token)->content[i] && (*token)->content[i] != '$')
		{
			(*expandedstr) = ft_charjoin((*expandedstr), (*token)->content[i]);
			i++;
		}
	}
}

void	expandtok(t_token *token, t_minishell *mshell)
{
	char	*expandedstr;
	char	*ret_expand;

	expandedstr = NULL;
	if (ft_strlen(token->content) == 0 || (token->quote != NULL
			&& ft_strncmp(token->quote, T_SQUOTE, 5) == 0))
		return ;
	expandtok_condition1(&token, &expandedstr, &ret_expand, &mshell);
	if (ft_strcmp(token->type, T_STRING) == 0)
		free(token->content);
	token->content = ft_strdup_seg(expandedstr);
	free(expandedstr);
}
