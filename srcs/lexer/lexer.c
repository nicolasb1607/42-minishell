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

int	is_known_type(char c, char ***typetok)
{
	
}

t_dlist	*tokenize(char *str, t_dlist *lexlst)
{
	int	i; 
	t_dlist *new;
	t_token tok;

	i = 0; 
	while (str[i])
	{
		is_known_type();
	}

	return (lexlst);
}