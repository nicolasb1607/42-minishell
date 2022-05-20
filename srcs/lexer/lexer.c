/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:50:57 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/20 12:56:04 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	make_quote_string(t_token *token, t_lexer *lexer)
{
	char	tquote;

	tquote = lexer->current_char;
	if (tquote == '\"')
		token->quote = T_DQUOTE;
	else
		token->quote = T_SQUOTE;
	if (lexer->text[lexer->pos + 1] == tquote)
	{
		token->content = "\0";
		advance(lexer);
	}
	else
	{
		advance(lexer);
		while (lexer->current_char != tquote)
		{
			token->content = ft_strnjoin_free(token->content,
					&lexer->current_char, 1);
			advance(lexer);
		}
	}
	if (lexer->text[lexer->pos + 1] && lexer->text[lexer->pos + 1] != ' ')
		token->space_after = 0;
	token->type = T_STRING;
}

static void	make_string_c(t_lexer **lexer, int *i)
{
	while ((*lexer)->current_char == '\'' || (*lexer)->current_char == '\"')
		*i += (advance((*lexer)), 1);
	if (*i % 2 != 0)
		ft_error("quote error");
}

int	make_string_b(int i, t_lexer *lexer, t_token *token)
{
	char	*tmp;

	tmp = ft_strnjoin_free(token->content, &lexer->current_char, 1);
	token->content = tmp;
	advance(lexer);
	if (lexer->text[lexer->pos]
		&& ft_containchar(lexer->text[lexer->pos + 1], "<>|") == 1)
	{
		if (lexer->current_char != ' ')
			token->content = ft_charjoin(token->content, lexer->current_char);
		return (1);
	}
	if ((lexer->current_char == '\'' && lexer->text[lexer->pos + 1] != '\'')
		|| (lexer->current_char == '\"'
			&& lexer->text[lexer->pos + 1] != '\"'))
	{
		token->space_after = 0;
		return (1);
	}
	else if ((lexer->current_char == '\''
			&& lexer->text[lexer->pos + 1] == '\'')
		|| (lexer->current_char == '\"'
			&& lexer->text[lexer->pos + 1] == '\"'))
		make_string_c(&lexer, &i);
	return (0);
}

void	make_string(t_token *token, t_lexer *lexer)
{
	int	i;

	i = 0;
	while (ft_isascii(lexer->current_char) == 1
		&& ft_iswhitespace(lexer->current_char) == 0)
	{
		if (make_string_b(i, lexer, token) == 1)
			break ;
	}
	token->type = T_STRING;
	if (lexer->current_char == '\"' || lexer->current_char == '\'')
		recul(lexer);
}

void	tok_operation(t_token *token, t_lexer *lexer)
{
	if (lexer->current_char == '>')
	{
		if (lexer->text[lexer->pos + 1] == '>')
		{
			assign_toks(token, ">>", T_DR_DIR);
			advance(lexer);
		}
		else
			assign_toks(token, ">", T_R_DIR);
	}
	else if (lexer->current_char == '<')
	{
		if (lexer->text[lexer->pos + 1] == '<')
		{
			assign_toks(token, "<<", T_DL_DIR);
			advance(lexer);
		}
		else
			assign_toks(token, "<", T_L_DIR);
	}
	else if (lexer->current_char == '|')
		assign_toks(token, "|", T_PIPE);
}
