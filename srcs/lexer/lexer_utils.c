/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:55 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 14:54:25 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	look_for_next_quote(char *str, char q, int *i)
{
	while (str[*i])
	{
		if (str[*i] == q)
			return (1);
		*i = *i + 1;
	}
	return (0);
}

static int	missing_quote_condition(char **str,
	char *quote, int *ret_check, int *i)
{
	*ret_check = look_for_next_quote(*str, *quote, i);
	if (*ret_check == 0)
	{	
		ft_putstr("Syntax error missing quote\n");
		return (0);
	}
	return (1);
}

int	check_quote(char *str)
{
	char	quote;
	int		i;
	int		ret_check;

	ret_check = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			quote = (i++, '\"');
			if (missing_quote_condition(&str, &quote, &ret_check, &i) == 0)
				return (0);
		}
		else if (str[i] == '\'')
		{
			quote = (i++, '\'');
			if (missing_quote_condition(&str, &quote, &ret_check, &i) == 0)
				return (0);
		}
	}
	return (1);
}

void	init_lexer(t_lexer *lexer, char *str)
{
	lexer->text = str;
	lexer->pos = -1;
	lexer->current_char = 0;
}
