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
	while(str[i])
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


/*

TO OD : 

--------------TOKEN-------------------------------
- Creation d une structure TOKEN (Type et value)
// - Creation fonction initialisation d un token, qui va assigner le type et la valeur 


-------------LEXER-------------------------------
- Creation d une structure LEXER (text, position, current char)
- Creation d un fonction d initialisation du lexe, qui va simplement attribuer la str que lon doit analyser, la pos a -1 et le current_char a 0.
- Creation d une fonction pour advance qui incremente la position du lexer ainsi que le current char en fonction de la position


- Creation d une fonction make_tokens qui prend en parametre le lexer

*/

void	init_lexer(t_lexer *lexer, char *str)
{
	lexer->text = str;
	lexer->pos = -1;
	lexer->current_char = 0;
}

void	init_token(t_token *token)
{
	token->content = NULL;
	token->type = NULL;
	token->quote = NULL;
}

void 	advance(t_lexer *lexer)
{
	char *str;

	lexer->pos += 1;
	str = lexer->text;
	if (str[lexer->pos])
		lexer->current_char = str[lexer->pos];
}

void	assign_toks(t_token *token, char *content, char *type)
{
	token->content = content;
	token->type = type;
}

void	make_quote_string(t_token *token, t_lexer *lexer)
{
	char tquote;
	tquote = lexer->current_char;
	advance(lexer);
	if (tquote == '\"')
		token->quote = T_DQUOTE;
	else
		token->quote = T_SQUOTE;
	// check expand si current char $
	while (lexer->current_char != tquote)
	{
		token->content = ft_charjoin(token->content, lexer->current_char);
		advance(lexer);
	}
	token->type = T_STRING;
} 

void	make_string(t_token *token, t_lexer *lexer)
{

	// est ce que le currentchar == $ ? 
	// si oui expand 
	// si non tu t en baleck
	while (ft_containchar(lexer->current_char, ALPHA) == 1)
	{
		token->content = ft_charjoin(token->content, lexer->current_char);
		advance(lexer);
	}
	token->type = T_STRING;
}

t_token	make_token(t_lexer *lexer)
{
	t_token token;

	init_token(&token);

	while (lexer->current_char)
	{
		if (lexer->current_char == '\"')
			make_quote_string(&token, lexer);
		else if (lexer->current_char == '\'')
			make_quote_string(&token, lexer);
		else if (ft_containchar(lexer->current_char, ALPHA) == 1)
			make_string(&token, lexer);
		else if (lexer->current_char == '>')
		{
			if (lexer->text[lexer->pos + 1] == '>')
			{
				assign_toks(&token, ">>", T_DR_DIR);
				advance(lexer);
			}
			else
				assign_toks(&token, ">", T_R_DIR);
		}
		else if (lexer->current_char == '<')
		{
			if (lexer->text[lexer->pos + 1] == '<')
			{
				assign_toks(&token, "<<", T_DL_DIR);
				advance(lexer);
			}
			else 
				assign_toks(&token, "<", T_L_DIR);
		}
		else if (lexer->current_char == '|')
			assign_toks(&token, "|", T_PIPE);
		advance(lexer);
	}
	return (token);
}

// Expand

// Cas ou il est tout seul
// Cas ou il est entre deux Simple quotes (le plus simple)
// Cas ou il est entre deux double quotes