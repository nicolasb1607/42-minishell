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

	// char *str = "echo -''''''n bonjou";
	// tlist = init_tlist(str, tlist, &mshell);
	// ft_printtoklst(tlist);
	// parser(tlist);
	// init_ft(tlist, mshell.head_env);
	// printf("premier free du main\n");
	// free_tlist(&tlist);


	char *ret;
	while (1)
	{
		ret = ft_prompt();
		if (ft_strlen(ret) != 0)
		{
			tlist = init_tlist(ret, tlist, &mshell);
			if (tlist)
			{
				parser(tlist);
				ft_printtoklst(tlist);
				init_ft(tlist, mshell.head_env);
				free_tlist(&tlist);
			}
		}
	}
	return (0);
}
