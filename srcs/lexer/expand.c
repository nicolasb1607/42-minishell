/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:53:33 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/03 12:17:334 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int ft_isenv(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else if (c == '_')
		return (1);
	return (0);
}

int is_valid_varenv(char *str)
{
	int i;

	i = 0;
	if (ft_isdigit(str[i++]) == 1)
		return (0);
	while (str[i])
	{
		if (ft_isenv(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char *look_for_varenv_value(char *varenv, t_dlist **env)
{
	char *val;
	char *subval;
	int i;
	t_dlist *curr;

	curr = *env;
	i = -1;
	while (curr)
	{
		if (ft_strncmp(get_var(curr->content), varenv, ft_strlen(varenv)) == 0 && ft_strlen(varenv) == ft_strlen(get_var(curr->content)))
		{
			val = curr->content;
			break;
		}
		curr = curr->next;
		if (!curr)
			return (NULL);
	}
	i = 0;
	while (val[i] != '=')
		i++;
	subval = ft_substr(val, i + 1, ft_strlen(val) - i);
	if (ft_strlen(subval) == 0)
		return (free(subval), NULL);
	return (subval);
}

char *expand(t_token *token, int i, t_minishell *mshell)
{
	char *varenv;
	char *varvalue;

	varenv = NULL;
	i++;
	while (token->content[i] && token->content[i] != ' ' && token->content[i] != '\'')
	{
		varenv = ft_charjoin(varenv, token->content[i]);
		i++;
	}
	if (is_valid_varenv(varenv) == 1)
		varvalue = look_for_varenv_value(varenv, mshell->head_env);
	free(varenv);
	return (varvalue);
}

int lenvarenv(char *str, int i)
{
	int j;

	j = 1;
	i++;
	while (str[i] && ft_isenv(str[i]) == 1)
	{
		j++;
		i++;
	}
	return (j);
}

void expandtok(t_token *token, t_minishell *mshell)
{
	int i;
	char *expandedstr;
	char *ret_expand;

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