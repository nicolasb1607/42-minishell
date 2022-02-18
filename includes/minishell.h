#ifndef MINISHELL_H

# define MINISHELL_H

typedef struct s_data
{
	char	**env;
}			t_data;

# include "libft.h"
# include <stdlib.h>
# include "prompt.h"
# include "pwd.h"
# include "env.h"
# include "cd.h"
# include "handle_sig.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>


#endif