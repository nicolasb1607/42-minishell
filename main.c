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

	printf("-----------------------------------------------\n");
	printf("-----------------------------------------------\n");
	printf("-----------------------------------------------\n");
	printf("-----------------------------------------------\n");
	printf("-----------------------------------------------\n");
	
	

	if (is_existing("PWD", mshell.head_env) == 1)
		printf("The value already exist\n");
	else
		printf("The value is not in the env\n");
	
	return (0);
}
