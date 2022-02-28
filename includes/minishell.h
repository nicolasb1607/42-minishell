#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include "prompt.h"
# include "pwd.h"
# include "env.h"
# include "cd.h"
# include "unset.h"
# include "export.h"
# include "pipe.h"
# include "lexer.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_minishell
{
	t_dlist	*env;
	t_dlist	**head_env;
}	t_minishell ;



#endif