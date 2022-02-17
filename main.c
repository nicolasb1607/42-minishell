#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	char	**dupenv;

	dupenv = ft_dupenv(envp);	
	ft_putchar('\n');
	ft_pwd();
	ft_cd("../yolo", dupenv);
	ft_pwd();

	ft_cd("../yolo", dupenv);
	ft_pwd();
	return (0);
}