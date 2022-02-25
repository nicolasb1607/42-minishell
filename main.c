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
	
	get_var("YOLO=ESTCEQUECAFONCTIONNE?");
		
	return (0);
}
