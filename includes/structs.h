#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

# define T_OPERATOR 1 // {'+','-','=','%', '*'}
# define T_SPECIAL 2// {'$'}
# define T_NUMBER 3 // {0-9}
# define T_QUOTE 4 // {'''}
# define T_DQUOTE 5 // {'"'}
# define T_PIPE 6 // {'|'}
# define T_R_DIR 7 // {'>'}
# define T_L_DIR 8 // {'<'}
# define T_DR_DIR 9 // {'>>'}
# define T_DL_DIR 10 // {'<<'}

# define T_STRING 11
# define T_PUNCTUATION  // {'{','}','(',')', '/', '.'}

typedef enum s_quotes
{
	SQUOTES = '\'',
	DQUOTES = '\"',
}	t_quotes;

typedef struct s_token
{
	char	*content; 
	int		*type; 
}			t_token;

typedef	enum s_spe
{
	PIPE = '|',
	R_DIR = '>',
	L_DIR = '<',
	ARG,
}			t_spe;

typedef	struct s_command
{
	char	*command;
}			t_command;

typedef	struct s_lex
{
	void	*token;
	struct s_lex	*next;
	struct s_lex	*prev;
}					t_lex;






typedef struct s_minishell
{
	t_lex	*lexer;
	t_dlist	*env;
	t_dlist	**head_env;
}	t_minishell ;



#endif