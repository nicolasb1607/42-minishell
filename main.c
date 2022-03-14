#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void) envp;
	t_minishell mshell;
	t_tlist *tlist;

	tlist = NULL;
	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;
	
	// ft_cd("yolo", mshell.head_env);
	//ft_env(mshell.head_env);
	
	char	*str = "export USER=\'$PWD\'"; 
	


	tlist = init_tlist(str, tlist, &mshell);

	//ft_printtoklst(tlist);

	printf ("----------------------------------------\n");

	parser(tlist);

	ft_export(tlist, mshell.head_env);
	ft_env(mshell.head_env);

	return (0);
}
