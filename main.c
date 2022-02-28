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

	char	str[] = "sdfjs kjsdfkjs jksdfkjsd   sdkjsfd queue ds,fsd jhsdfkj";
	char	**tab;
	t_token	*tok;

	tok = NULL;
	tab = ft_split(str, ' ');
	tok = tab_to_list(tab, tok);
	while (tok)
	{
		printf("%s\n", tok->content);
		tok = tok->next;
	}
}
