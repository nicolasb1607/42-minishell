/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:27:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 13:27:48 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*make_token(t_lexer *lexer)
{
	t_token	*token;

	token = init_token();
	if (lexer->current_char == 0)
		token->content = NULL;
	if (lexer->current_char == '\"' && lexer->pos < (int)ft_strlen(lexer->text))
		make_quote_string(token, lexer);
	else if (lexer->current_char == '\'')
		make_quote_string(token, lexer);
	else if (ft_containchar(lexer->current_char, ">|<") == 1)
		tok_operation(token, lexer);
	else if (ft_isascii(lexer->current_char) == 1
		&& ft_iswhitespace(lexer->current_char) == 0)
		make_string(token, lexer);
	if (lexer->current_char != 0)
		advance(lexer);
	return (token);
}
