#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_test test;

	test.env = ft_dupenv(envp);
	ft_env(test.env);
	

	printf("-----------------------------------------------\n");
	test.env = ft_unset("PWD", test.env);
	ft_cd("../", test.env);
	
	ft_env(test.env);
	printf("apres avoir supprimer la PWD\n");
	ft_pwd();
	free_tab((test.env));
	return (0);
}
