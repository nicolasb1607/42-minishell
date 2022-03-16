#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	t_minishell mshell;
	t_tlist *tlist;

	tlist = NULL;
	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;

	char *str = "cd ../";

	tlist = init_tlist(str, tlist, &mshell);

	launch_cd(tlist, mshell.head_env);

	ft_env(mshell.head_env);

	// while (1)
	// {
	// 	char *ret = ft_prompt();

	// 	tlist = init_tlist(ret, tlist, &mshell);

	// 	ft_printtoklst(tlist);

	// 	parser(tlist);w
	// }
	return (0);
}
