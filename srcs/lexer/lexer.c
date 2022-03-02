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

void 	advance(t_lexer *lexer)
{
	char *str;

	lexer->pos += 1;
	str = lexer->text;
	if (str[lexer->pos])
		lexer->current_char = str[lexer->pos];
}


t_token	make_token(t_lexer *lexer)
{
	t_token token;

	

	return (token);
}


