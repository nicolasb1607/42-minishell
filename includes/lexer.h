#ifndef LEXER_H

# define LEXER_H

# include "minishell.h"
# include <errno.h>

int		check_quote(char *str);
int		look_for_next_quote(char *str, char q, int *i);
int		ft_isenv(char c);
int		is_valid_varenv(char *str);
char	*look_for_varenv_value(char *varenv, t_dlist **env);
char	*expand( t_lexer *lexer, t_minishell *mshell);

#endif