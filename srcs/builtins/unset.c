#include "unset.h"


/*
 - la variable demandee existe elle ? 
	--> Si oui, la supprimer de l environnement
	--> Non, display une erreur "la variable n existe pas"
*/

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_existing(char *varenv, char **dupenv)
{
	int	i;
	int	lentoequal;

	i = 0;
	
	while (dupenv[i])
	{
		lentoequal = 0;
		while (dupenv[i][lentoequal] && dupenv[i][lentoequal] != '=')
			lentoequal++;
		printf("value of lentoequal = %d\n", lentoequal);
		if(ft_strncmp(dupenv[i], varenv, lentoequal) == 0)
		{
			printf("IS EXISTING \n");
			return (1);
		}
		i++;
	}
	return (0);
}

char	**ft_unset(char *varenv, char **dupenv)
{
	int		i;
	int		j;
	char	**newenv;

	if(is_existing(varenv, dupenv) == 0)
		return (dupenv);
	newenv = malloc(sizeof(char *) * ft_tablen(dupenv));
	if (!newenv)
		return (NULL);
	i = 0;
	j = 0;
	while(dupenv[i])
	{
		if (ft_strncmp(dupenv[i], varenv, ft_strlen(varenv)) != 0)
			newenv[j++] = ft_strdup(dupenv[i]);
		i++;
	}
	newenv[j] = NULL;
	free_tab(dupenv);
	return (newenv);
}