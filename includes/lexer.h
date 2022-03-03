#ifndef LEXER_H

# define LEXER_H

# include "minishell.h"
# include <errno.h>

int		look_for_next_quote(char *str, char q, int *i);
int		check_quote(char *str);
void	init_lexer(t_lexer *lexer, char *str);
void	init_token(t_token *token);
void 	advance(t_lexer *lexer);
void	assign_toks(t_token *token, char *content, char *type);
void	make_quote_string(t_token *token, t_lexer *lexer, t_minishell *mshell);
void	make_string(t_token *token, t_lexer *lexer, t_minishell *mshell);
t_token	make_token(t_lexer *lexer);
int		ft_isenv(char c);
int		is_valid_varenv(char *str);
char	*look_for_varenv_value(char *varenv, t_dlist **env);
char	*expand( t_lexer *lexer, t_minishell *mshell);

#endif