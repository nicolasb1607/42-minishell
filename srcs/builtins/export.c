/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 17:38:57 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

/* TODO : 

- Ne pas oublier de check si la variable que l on souhaite creer 
	correspond aux standards 
du nommage des variable d environnement a savoir 
		- Seulement Des ALphanum et des UNDERSCORE
		- Ne doit pas commencer par un digit 

*/

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
	char	*varexport;
	t_dlist	*curr;
	t_dlist	*new;

	varexport = get_var(varnvalue);
	if (!varexport)
		return ;
	if (is_existing(varexport, dupenv) == 1)
	{
		curr = *dupenv;
		while (curr)
		{
			if (ft_strncmp(curr->content, varexport, ft_strlen(varexport)) == 0)
			{
				free(curr->content);
				curr->content = ft_strdup(varnvalue);
				return ;
			}
			curr = curr->next;
		}
	}
	new = ft_dlstnew(ft_strdup(varnvalue));
	ft_dlstadd_back(dupenv, new);
}
