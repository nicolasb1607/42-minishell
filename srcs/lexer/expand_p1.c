/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_p1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:11:02 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/24 10:29:53 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_isenv(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else if (c == '_')
		return (1);
	return (0);
}

int	is_valid_varenv(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_isdigit(str[i++]) == 1)
		return (0);
	while (str[i])
	{
		if (ft_isenv(str[i]) == 0)
		{
			ft_putstr(str);
			ft_putstr (" is not a valid variable\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	*get_corresponding_val(char *varenv, t_dlist *curr)
{
	char	*val;

	while (curr)
	{
		if (ft_strncmp(get_var(curr->content), varenv, ft_strlen(varenv)) == 0
			&& ft_strlen(varenv) == ft_strlen(get_var(curr->content)))
		{
			val = curr->content;
			break ;
		}
		curr = curr->next;
		if (!curr)
			return (NULL);
	}
	return (val);
}

char	*look_for_varenv_value(char *varenv, t_dlist **env)
{
	char	*val;
	char	*subval;
	int		i;
	t_dlist	*curr;

	curr = *env;
	i = -1;
	val = get_corresponding_val(varenv, curr);
	i = 0;
	if (!val)
		return (NULL);
	while (val[i] != '=')
		i++;
	subval = ft_substr(val, i + 1, ft_strlen(val) - i);
	if (ft_strlen(subval) == 0)
		return (free(subval), NULL);
	return (subval);
}

char	*expand(t_token *token, int i, t_minishell *mshell)
{
	char	*varenv;
	char	*varvalue;

	varenv = NULL;
	i++;
	while (token->content[i] && token->content[i] != ' '
		&& token->content[i] != '\'' && token->content[i] != '=')
	{
		varenv = ft_charjoin(varenv, token->content[i]);
		i++;
	}
	if (is_valid_varenv(varenv) == 1)
		varvalue = look_for_varenv_value(varenv, mshell->head_env);
	free(varenv);
	return (varvalue);
}
