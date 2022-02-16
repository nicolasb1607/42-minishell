#include "./includes/minishell.h"

int main(int ac, char **av, char **envp)
{
	char **dupenv;
	int i = 0;

	(void)ac;
	(void)av;
	// while(1)
	// {
	dupenv = ft_env(envp);
	while (dupenv[i])
	{
		printf("%s\n", dupenv[i]);
		i++;
	}
	

	// }
	return (0);
}