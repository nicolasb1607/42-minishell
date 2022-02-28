#include "lexer.h"

int	check_lexer(char *str)
{
	int nbr_squote; 
	int nbr_dquote;
	int	i; 

	nbr_squote = 0;
	nbr_dquote = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			nbr_squote++;
		if (str[i] == '\"')
			nbr_dquote++;
	}
	if (nbr_squote % 2 == 0 && nbr_dquote % 2 == 0) 
		return (1);
	return (0);	
}

