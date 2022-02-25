#ifndef EXPORT_H

# define EXPORT_H

# include "minishell.h"

char	*get_var(char *varnvalue);
void	ft_export(char *varnvalue, t_dlist **dupenv);

#endif