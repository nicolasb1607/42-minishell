/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:21:43 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/23 13:05:25 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	advance(t_lexer *lexer)
{
	char	*str;

	lexer->pos += 1;
	str = lexer->text;
	if (str[lexer->pos])
		lexer->current_char = str[lexer->pos];
	else
		lexer->current_char = 0;
}

void	recul(t_lexer *lexer)
{
	char	*str;

	lexer->pos = lexer->pos - 1;
	str = lexer->text;
	if (str[lexer->pos])
		lexer->current_char = str[lexer->pos];
	else
		lexer->current_char = 0;
}

void	make_quote_string(t_token *token, t_lexer *lexer)
{
	char	tquote;

	tquote = lexer->current_char;
	if (tquote == '\"')
		token->quote = T_DQUOTE;
	else
		token->quote = T_SQUOTE;
	if(lexer->text[lexer->pos + 1] == tquote)
	{
		token->content = malloc(sizeof(char));
		token->content = "\0";
		advance(lexer);
	}
	else
	{
		advance(lexer);
		while (lexer->current_char != tquote)
		{
			token->content = ft_charjoin(token->content, lexer->current_char);
			advance(lexer);
		}
	}
	if (lexer->text[lexer->pos + 1] && lexer->text[lexer->pos + 1] != ' ')
		token->space_after = 0;
	token->type = T_STRING;
}

void	make_string(t_token *token, t_lexer *lexer)
{
	int	i;

	i = 0;
	while (ft_isascii(lexer->current_char) == 1
		&& ft_iswhitespace(lexer->current_char) == 0 )
	{
		token->content = ft_charjoin(token->content, lexer->current_char);
		advance(lexer);
		if (ft_containchar(lexer->text[lexer->pos + 1], "<>|") == 1 )
		{	
			token->content = ft_charjoin(token->content, lexer->current_char);
			break ;
		}
		if ((lexer->current_char == '\'' && lexer->text[lexer->pos + 1] != '\'') || (lexer->current_char == '\"' && lexer->text[lexer->pos + 1] != '\"'))
		{
			token->space_after = 0;
			break;
		}
		else if ((lexer->current_char == '\'' && lexer->text[lexer->pos + 1] == '\'') || (lexer->current_char == '\"' && lexer->text[lexer->pos + 1] == '\"'))
		{
			while (lexer->current_char == '\'' || lexer->current_char == '\"')
				i += (advance(lexer), 1);
			printf("value i = %d\n", i);
			if (i % 2 != 0)
				ft_error("quote error");
		}
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
	else if (ft_containchar(lexer->current_char, ">|<") == 1 )
		tok_operation(token, lexer);
	else if (ft_isascii(lexer->current_char) == 1
		&& ft_iswhitespace(lexer->current_char) == 0)
		make_string(token, lexer);
	if (lexer->current_char != 0)
		advance(lexer);
	return (token);
}
