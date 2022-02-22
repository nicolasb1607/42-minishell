#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_data data;

	data.env = ft_dupenv(envp);
	printf("Avant le UNSET\n\n");
	ft_env(data.env);
	
	printf("Apres le UNSET\n\n");
	
	data.env = ft_unset("USER", data.env);
	
	ft_env(data.env);

	return (0);
}