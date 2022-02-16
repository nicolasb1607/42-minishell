#include "env.h"

char	**ft_env(char **envp)
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