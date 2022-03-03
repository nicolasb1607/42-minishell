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

int	ft_isenv(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else if (c == '_');
	return (0);
}

int	is_valid_varenv(char *str)
{
	int	i;

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

char *look_for_varenv_value(char *varenv, char **env)
{
	char	*val;
	char	*subval;
	int		i;

	i = -1;
	while (env[++i])
	{
		val = ft_strnstr(env[i], varenv, ft_strlen(env[i]));
		if (!val)
			return (NULL);
	}
	i = 0;
	while (val[i] != '=')
		i++;
	subval = ft_substr(val, i, ft_strlen(val) - (i + 1));
	free(val);
	return (subval);
}


char	*expand( t_lexer *lexer, t_minishell *mshell)
{
	int	i;
	char *varenv;
	char *varvalue;
	
	varenv = NULL;
	i = 1;
	while(lexer->text[lexer->pos + i] && lexer->text[lexer->pos + i] != ' ')
	{
		varenv = ft_charjoin(varenv, lexer->text[lexer->pos + i]);
		i++;
	}
	if(is_valid_varenv(varenv) == 1)
	{
		varvalue = look_for_varenv_value(varenv, mshell->env);
	}
	free(varenv);
	return (varvalue);
}