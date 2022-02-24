#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_minishell mshell;
	

	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;
	ft_env(mshell.head_env);

	// printf("-----------------------------------------------\n");
	// test.env = ft_unset("PWD", test.env);
	// ft_cd("../", test.env);
	
	// ft_env(test.env);
	// printf("apres avoir supprimer la PWD\n");
	// ft_pwd();
	// free_tab((test.env));
	return (0);
}
