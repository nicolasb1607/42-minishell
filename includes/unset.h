#ifndef UNSET_H

# define UNSET_H

# include "minishell.h"

int	is_existing(char *varenv, char **dupenv);
char	**ft_unset(char *varenv, char **dupenv);
void	free_tab(char **tab);


#endif