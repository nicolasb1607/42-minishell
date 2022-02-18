#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_data data;

	signal(SIGINT, handle_ctrlc);

	data.env = ft_dupenv(envp);	
	ft_pwd();
	ft_cd("../yolo", data.env);
	ft_pwd();

	ft_cd("../yolo", data.env);
	ft_pwd();
	return (0);
}