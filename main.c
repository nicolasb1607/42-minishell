#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_dlist *lstenv;
	t_dlist **alstenv;

	lstenv = NULL;
	lstenv = ft_dupenv(lstenv, envp);
	alstenv = &lstenv;
	ft_env(alstenv);

	// printf("-----------------------------------------------\n");
	// test.env = ft_unset("PWD", test.env);
	// ft_cd("../", test.env);
	
	// ft_env(test.env);
	// printf("apres avoir supprimer la PWD\n");
	// ft_pwd();
	// free_tab((test.env));
	return (0);
}
