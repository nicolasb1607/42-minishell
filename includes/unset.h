#ifndef UNSET_H

# define UNSET_H

# include "minishell.h"

int	is_existing(char *varenv, t_dlist **dupenv);
void	ft_unset(char *varenv, t_dlist **dupenv);
void	free_tab(char **tab);


#endif