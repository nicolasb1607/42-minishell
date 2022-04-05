#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	// (void)envp;
	t_minishell mshell;
	t_tlist *tlist;
	t_cmd *cmd;
	t_cmd **chead;
	
	cmd = NULL;
	chead = &cmd;
	tlist = NULL;
	mshell.env = NULL;
	mshell.env = ft_dupenv(mshell.env, envp);
	mshell.head_env = &mshell.env;

	// char *str = "echo $QUEUE oui";
	// tlist = init_tlist(str, tlist, &mshell);
	// ft_printtoklst(tlist);
	// parser(tlist);
	// init_ft(tlist, mshell.head_env);
	// printf("premier free du main\n");
	// free_tlist(&tlist);

	// tlist = init_tlist(str, tlist, &mshell);
	// ft_printtoklst(tlist);

	/* EXECUTION MAIN */
	
	// if (tlist)
	// {
	// 	char	**path;
	// 	t_cmd	*cmd;
	// 	char	**tabenv;
	// 	pid_t	pipi;
	// 	int		ret;

	// 	cmd = tlst_to_cmd(tlist);
	// 	path = get_path_to_cmd(tlist, mshell.head_env);
	// 	update_bin(path, cmd);
	// 	tabenv = dlist_to_tab(mshell.env);

	// 	if (cmd->is_absolute)
	// 	{
	// 		pipi = fork();
	// 		if (pipi == 0)
	// 		{
	// 			ret = execve(cmd->command, cmd->options, tabenv);
	// 			printf("Ret -> %d\n", ret);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		pipi = fork();
	// 		if (pipi == 0)
	// 		{
	// 			ret = execve(cmd->bin, cmd->options, tabenv);
	// 			printf("Ret -> %d\n", ret);
	// 		}
	// 	}
	// 	waitpid(pipi, NULL, 0);
	// }


	/* PROMPT MAIN */

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
				ft_printalltok(tlist);
				init_ft(tlist, mshell.head_env, cmd, chead);
				printf("Nombre de commandes : %d\n", count_command(tlist));
				free_tlist(&tlist);
			}
		}
	}
	return (0);
}
