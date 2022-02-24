#include "unset.h"

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

int	is_existing(char *varenv, t_dlist **dupenv)
{
	int	lentoequal;
	char *content;
	t_dlist *curr;

	curr = *dupenv;	
	while (curr)
	{
		content = curr->content;
		lentoequal = 0;
		while (content[lentoequal] && content[lentoequal] != '=')
			lentoequal++;
		if (ft_strncmp(content, varenv, lentoequal) == 0)
			return(1);
		curr = curr->next;	
	}
	return (0);
}

// char	**ft_unset(char *varenv, char **dupenv)
// {
// 	int		i;
// 	int		j;
// 	char	**newenv;

// 	if(is_existing(varenv, dupenv) == 0)
// 		return (dupenv);
// 	newenv = malloc(sizeof(char *) * ft_tablen(dupenv));
// 	if (!newenv)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while(dupenv[i])
// 	{
// 		if (ft_strncmp(dupenv[i], varenv, ft_strlen(varenv)) != 0)
// 			newenv[j++] = ft_strdup(dupenv[i]);
// 		i++;
// 	}
// 	newenv[j] = NULL;
// 	free_tab(dupenv);
// 	return (newenv);
// }