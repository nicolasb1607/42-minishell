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

void	handle_ctrlc(t_data *data)
{
	if(data->env)
		free_env(data->env);
}

// void	handle_ctrld(void)
// {
 
// }

// void	handle_ctrlbslash(void)
// {

// }


