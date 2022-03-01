#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void) envp;
	// t_minishell mshell;


	// mshell.env = NULL;
	// mshell.env = ft_dupenv(mshell.env, envp);
	// mshell.head_env = &mshell.env;
	// ft_env(mshell.head_env);

	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	// printf("-----------------------------------------------\n");
	
	// ft_export("PWONCTIONNEOUPAS", mshell.head_env);

	// ft_env(mshell.head_env);		

	char	str[] = "sdfjs kjsdf\'kjs jksd\'fkjsdsdkjsfd que\'ue ds,fsd \'jhsdfkj";

	if (check_quote(str) == 0)
		printf("Wrong fromat\n");
	else 
		printf("Putain ca marche\n");
	
	return (0);
}
