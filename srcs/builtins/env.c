#include "env.h"

char	**ft_dupenv(char **envp)
{
		int i;
	char **dupenv;

	i = 0;
	while (envp[i])
		i++;
	dupenv = malloc(sizeof(char *) * (i + 1));
	if (!dupenv)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		dupenv[i] = ft_strdup(envp[i]);
		i++;
	}
	return (dupenv);
}

void	ft_env(char **dupenv)
{
	int i;
	
	i = 0;
	while (dupenv[i])
	{
		ft_putstr(dupenv[i]);
		ft_putchar('\n');
		i++;
	}
}