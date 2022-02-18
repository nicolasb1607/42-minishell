#include "handle_sig.h"

static void	free_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		i++;
	}
	free(data->env);
}

void	handle_sig(int signum, siginfo_t *si_signo , void * data)
{
	(void)si_signo;
	if(signum == SIGINT && data->env)
		free_env(data->env);
}

// // void	handle_ctrld(void)
// // {
 
// // }

// // void	handle_ctrlbslash(void)
// // {

// // }


