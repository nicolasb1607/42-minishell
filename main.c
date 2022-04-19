#include "minishell.h"
#include "structs.h"

/*
!	TODO :
!		Pipes :
!			- Faire en sorte que quand on a des options apres une redirection, elles soient prisent en compte
!			- Créer les fichiers (En O_APPEND si drdir, en O_TRUNC si simple rdir)

?	NOTES :
?	Quand on a une redirection puis un pipe on va reset le fd de sortie des commandes
*/

t_minishell g_mshell;

void handler_main(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_mshell.err_exit = 130;
	}
}

void handler_cmd(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		g_mshell.err_exit = 130;
	}
}

int main(int ac, char **av, char **envp)
{
	t_tlist *tlist;
	t_cmd *chead;
	char *ret;

	(void)ac;
	(void)av;
	chead = NULL;
	// chead->next = NULL;
	// chead->prev = NULL;
	tlist = NULL;
	g_mshell.env = NULL;
	g_mshell.env = ft_dupenv(g_mshell.env, envp);
	g_mshell.head_env = &g_mshell.env;

	/* PROMPT MAIN */
	while (1)
	{
		signal(SIGINT, handler_main);
		signal(SIGQUIT, SIG_IGN);

		ret = ft_prompt();
		if (ft_strlen(ret) != 0)
		{
			tlist = init_tlist(ret, tlist, &g_mshell);
			ft_printtoklst(tlist);
			// printf("Number of commands : %d\n", count_command(tlist));
			if (tlist)
			{
				if (parser(tlist))
				{
					if (count_command(tlist) == 1)
						only1cmd(tlist, g_mshell.head_env, chead);
					else
						init_ft(tlist, g_mshell.head_env, chead);
					free_tlist(&tlist);
					free_tcmd(&chead);
					chead = NULL;

				}
				else
					free_tlist(&tlist);
			}
		}
	}
	exit(0);
}
