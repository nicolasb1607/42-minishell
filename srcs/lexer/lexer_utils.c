/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:55 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/23 11:27:36 by ngobert          ###   ########.fr       */
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

int	check_quote(char *str)
{
	char	quote;
	int		i;
	int		ret_check;

	ret_check = 0;
	i = 0;
	if (!ft_containchar('\"', str) && !ft_containchar('\'', str))
		return (1);
	while (str[i])
	{
		if (str[i] == '\"')
		{
			quote = (i++, '\"');
			ret_check = look_for_next_quote(str, quote, &i);
			if (ret_check == 0)
				return (0);
		}
		else if (str[i] == '\'')
		{
			quote = (i++, '\'');
			ret_check = look_for_next_quote(str, quote, &i);
			if (ret_check == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

// int	check_cool(char *str, char c)
// {
	
// }

// int	check_quote_v2(char *str)
// {
// 	char	s;
// 	char	d;

// 	s = 0;
// 	d = 0;
// 	if (!ft_containchar('\"', str) || ft_containchar('\'', str))
// 		return (1);
// 	if (check_cool(str, '\'') == 0)
// 		return (0);
// 	else if (check_cool(str, '\'') == 0)
// 		return (0);
// }

void	init_lexer(t_lexer *lexer, char *str)
{
	lexer->text = str;
	lexer->pos = -1;
	lexer->current_char = 0;
}

t_token	*init_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = NULL;
	token->type = NULL;
	token->quote = NULL;
	token->space_after = 1;
	return (token);
}

void	assign_toks(t_token *token, char *content, char *type)
{
	token->content = content;
	token->type = type;
}
