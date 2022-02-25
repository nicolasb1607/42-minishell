#include "export.h"


char	*get_var(char *varnvalue)
{
	char	*varexport;
	int		i;

	varexport = NULL;
	i = 0;
	if (ft_containchar('=', varnvalue) == 0)
		return (NULL);
	while (varnvalue[i] && varnvalue[i] != '=')
		i++;
	varexport = ft_strncpy(varnvalue, i);
	return (varexport);
}

void	ft_export(char *varnvalue, t_dlist **dupenv)
{
	char *varexport;

	varexport = get_var(varnvalue);
	if (is_existing(varexport, dupenv) == 
}