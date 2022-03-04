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
	

	char	*str = "Salut \"$PWD test dquote\" qq6ch   780 derriere";

	tlist = init_tlist(str, tlist, &mshell);

	ft_printtoklst(tlist);

	return (0);
}
