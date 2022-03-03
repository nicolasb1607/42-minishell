#ifndef LEXER_H

# define LEXER_H

# include "minishell.h"
# include <errno.h>

int	check_quote(char *str);
int	look_for_next_quote(char *str, char q, int *i);

#endif