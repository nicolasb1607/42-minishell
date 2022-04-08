#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_minishell mshell;
	t_tlist *tlist;
	t_cmd *chead;
	
	chead = NULL;
	tlist = NULL;
	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;

	/* PROMPT MAIN */

	char *ret;
	while (1)
	{
		ret = ft_prompt();
		if (ft_strlen(ret) != 0)
		{
			tlist = init_tlist(ret, tlist, &mshell);
			printf("Number of commands : %d\n", count_command(tlist));
			if (tlist)
			{
				parser(tlist);
				ft_printtoklst(tlist);
				ft_printalltok(tlist);
				if (count_command(tlist) == 1)
					only1cmd(tlist, mshell.head_env, chead);
				else
					init_ft(tlist, mshell.head_env, chead);
				free_tlist(&tlist);
				free_tcmd(&chead);
				chead = NULL;
			}
		}
	}
	return (0);
}
