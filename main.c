#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	t_minishell mshell;
	t_tlist *tlist;
	char *ret;


	tlist = NULL;
	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;

	// char *str = "cd ../";

	// tlist = init_tlist(str, tlist, &mshell);

	// launch_cd(tlist, mshell.head_env);

	// ft_env(mshell.head_env);

	while (1)
	{
		ret = ft_prompt();

		tlist = init_tlist(ret, tlist, &mshell);

		parser(tlist);

		init_ft(tlist, mshell.head_env);

		free_tlist(tlist);
		//ft_printtoklst(tlist);
	}
	return (0);
}
