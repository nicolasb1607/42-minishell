#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	char	**dupenv;
	char	*currdir;

	dupenv = ft_dupenv(envp);	
	ft_putchar('\n');
	currdir = ft_pwd();
		printf("%s\n", currdir);

	ft_cd("../yolo", dupenv);
	currdir = ft_pwd();
		printf("%s\n", currdir);

	ft_cd("../yolo", dupenv);
	currdir = ft_pwd();
		printf("%s\n", currdir);
	return (0);
}