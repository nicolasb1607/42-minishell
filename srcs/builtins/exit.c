/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:08 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/23 14:23:09 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static int	ft_exit_error_arg(t_cmd **cmd, int *i)
{
	int	neg;

	neg = 0;
	if ((*cmd)->options[1][*i] == '-'
		|| (*cmd)->options[1][*i] == '+')
	{
		if ((*cmd)->options[1][*i] == '-')
			neg = 1;
		*i = *i + 1;
	}
	if (ft_isdigit((*cmd)->options[1][*i]) == 0)
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		return (1);
	}
	if (neg == 1)
		return (2);
	return (0);
}

static void	exit_number(int error_arg, char *exit_val)
{
	if (error_arg == 1)
		exit(2);
	if (error_arg == 2)
		exit(ft_atoll(exit_val) * -1 % 256);
	if (exit_val == NULL)
		exit(0);
	else
		exit(ft_atoll(exit_val) % 256);
}

void	ft_exit(t_cmd **cmd)
{
	char	*exit_val;
	int		i;
	int		error_arg;

	if (g_mshell.err_exit && !(*cmd)->options[1])
		exit_val = ft_itoa(g_mshell.err_exit);
	else if ((*cmd)->options[1] && ft_strlen((*cmd)->options[1]) <= 19)
	{
		exit_val = NULL;
		error_arg = 0;
		i = 0;
		if ((*cmd)->options[1])
		{
			error_arg = ft_exit_error_arg(cmd, &i);
			while ((*cmd)->options[1][i]
				&& ft_isdigit((*cmd)->options[1][i]) == 1)
			{
				exit_val = ft_charjoin(exit_val, (*cmd)->options[1][i]);
				i++;
			}
		}
	}
	i = (ft_printf(RED "exit\n" CRESET), free_dlist(&g_mshell.env),
			free_tcmd(cmd), rl_clear_history(), unlink_hd(), 0);
	exit_number(error_arg, exit_val);
}

void	disp_synt_erro(char *str)
{
	ft_printf("minishell: syntax error near unexpected token \'%s\'\n", str);
}

void	ft_error(char *str)
{
	ft_printf(RED "%s\n" CRESET, str);
}
