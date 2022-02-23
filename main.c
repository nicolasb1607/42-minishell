#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_data data;

	data.env = ft_dupenv(envp);
	ft_env(data.env);
	

	printf("-----------------------------------------------\n");
	data.env = ft_unset("PWD", data.env);
	ft_cd("../", data.env);
	
	ft_env(data.env);
	printf("apres avoir supprimer la PWD\n");
	ft_pwd();
	free_tab((data.env));
	return (0);
}
