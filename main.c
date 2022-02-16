#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	char *dupenv;

	(void)ac;
	(void)av;
	(void)envp;
	// while(1)
	// {
	dupenv = ft_pwd();
		printf("%s\n", dupenv);
	// }
	return (0);
}