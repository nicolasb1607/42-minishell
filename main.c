#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void) envp;
	t_minishell mshell;


	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;
	// ft_env(mshell.head_env);

	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	
	// ft_export("PWONCTIONNEOUPAS", mshell.head_env);

	// ft_env(mshell.head_env);		

	char	*str = "XDG_SESSION_CLASS";

	if (look_for_varenv_value(str, mshell.head_env) == NULL)
		printf("doesnt exist\n");
	else
		printf("%s\n", look_for_varenv_value(str, mshell.head_env));
	return (0);
}
