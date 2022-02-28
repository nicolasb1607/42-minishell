#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

# define T_ARG 1
# define T_R_DIR 2
# define T_L_DIR 3
# define T_DR_DIR 4
# define T_DL_DIR 5
# define T_PIPE 6

typedef struct s_minishell
{
	t_dlist	*env;
	t_dlist	**head_env;
}	t_minishell ;

// typedef struct s_quotes
// {
	  
// };

typedef	struct s_token
{
	char	*content;
	int		type;
	struct s_token	*next;
}			t_token;


#endif