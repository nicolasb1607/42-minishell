/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:21:43 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/04 12:02:555 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int look_for_next_quote(char *str, char q, int *i)
{
	while (str[*i])
	{
		if (str[*i] == q)
			return (1);
		*i = *i + 1;
	}
	return (0);
}

int check_quote(char *str)
{
	char quote;
	int i;
	int ret_check;

	ret_check = 0;
	i = 0;
	if (!ft_containchar('\"', str) || !ft_containchar('\'', str) )
		return (1);
	while (str[i])
	{
		if (str[i] == '\"')
		{
			quote = (i++, '\"');
			ret_check = look_for_next_quote(str, quote, &i);
		}
		else if (str[i] == '\'')
		{
			quote = (i++, '\'');
			ret_check = look_for_next_quote(str, quote, &i);
		}
		i++;
	}
	if (ret_check == 0)
		return (0);
	return (1);
}

void init_lexer(t_lexer *lexer, char *str)
{
	lexer->text = str;
	lexer->pos = -1;
	lexer->current_char = 0;
}

t_token *init_token(void)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = NULL;
	token->type = NULL;
	token->quote = NULL;
	return (token);
}

void advance(t_lexer *lexer)
{
	char *str;

	lexer->pos += 1;
	str = lexer->text;
	if (str[lexer->pos])
		lexer->current_char = str[lexer->pos];
	else
		lexer->current_char = 0;
}

void assign_toks(t_token *token, char *content, char *type)
{
	token->content = content;
	token->type = type;
}

void make_quote_string(t_token *token, t_lexer *lexer)
{
	char tquote;

	tquote = lexer->current_char;
	if (tquote == '\"')
		token->quote = T_DQUOTE;
	else
		token->quote = T_SQUOTE;
	advance(lexer);
	while (lexer->current_char != tquote)
	{
		token->content = ft_charjoin(token->content, lexer->current_char);
		advance(lexer);
	}

	token->type = T_STRING;
}

void make_string(t_token *token, t_lexer *lexer)
{
	while (ft_isascii(lexer->current_char) == 1 && ft_iswhitespace(lexer->current_char) == 0)
	{
		token->content = ft_charjoin(token->content, lexer->current_char);
		advance(lexer);
	}
	token->type = T_STRING;
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

t_token *make_token(t_lexer *lexer)
{
	t_token *token;

	token = init_token();
	if (lexer->current_char == 0)
		token->content = NULL;
	if (lexer->current_char == '\"' && lexer->pos < (int)ft_strlen(lexer->text))
		make_quote_string(token, lexer);
	else if (lexer->current_char == '\'')
		make_quote_string(token, lexer);
	else if (ft_containchar(lexer->current_char, ">|<") == 1 )
		tok_operation(token, lexer);
	else if (ft_isascii(lexer->current_char) == 1 && ft_iswhitespace(lexer->current_char) == 0)
		make_string(token, lexer);
	if (lexer->current_char != 0)
		advance(lexer);
	return (token);
}

t_tlist *init_tlist(char *str, t_tlist *tlist, t_minishell *mshell)
{
	t_tlist *new;
	t_token *token;
	t_lexer lexer;
	
	if (check_quote(str) == 0)
		return (NULL);
	init_lexer(&lexer, str);
	advance(&lexer);
	while (lexer.current_char != 0)
	{
		while (ft_iswhitespace(lexer.current_char) == 1)
			advance(&lexer);
		token = make_token(&lexer);
		if(!token->content)
			break ;
		new = ft_tlstnew(token);
		ft_tlstadd_back(&tlist, new);
	}
	ft_tlstiter(tlist, mshell, expandtok);
	return (tlist);
}
