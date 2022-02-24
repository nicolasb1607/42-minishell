#ifndef ENV_H

# define ENV_H

# include "minishell.h"

t_dlist *ft_dupenv(t_dlist *lst, char **envp);
void	ft_env(t_dlist **dupenv);



#endif