/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_p3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:25:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/19 13:25:48 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*expand(t_token *token, int i, t_minishell *mshell)
{
	char	*varenv;
	char	*varvalue;

	varenv = NULL;
	i++;
	while (token->content[i] && (ft_isalnum(token->content[i]) == 1
			|| token->content[i] == '?'))
	{
		if (token->content[i] == '?')
		{
			varenv = ft_strdup("?");
			break ;
		}
		varenv = ft_charjoin(varenv, token->content[i]);
		i++;
	}
	if (ft_strncmp(varenv, "?", 2) == 0)
		varvalue = ft_itoa(mshell->err_exit);
	else
		varvalue = look_for_varenv_value(varenv, &mshell->env);
	free(varenv);
	return (varvalue);
}
