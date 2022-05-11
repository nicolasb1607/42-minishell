/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:08 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/10 14:02:19 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static int	ft_exit_error_arg(t_tlist **tlst, int *i)
{
	if (ft_isdigit((*tlst)->next->token->content[*i]) == 0)
	{
		ft_putstr("minishell: exit: numeric argument required\n");
		return (1);
	}
	return (0);
}

static void	exit_number(int error_arg, char *exit_val)
{
	if (error_arg == 1)
		exit(2);
	if (exit_val == NULL)
		exit(0);
	else
		exit(ft_atoi(exit_val) % 256);
}

void	ft_exit(t_tlist *tlst, t_cmd **cmd)
{
	char	*exit_val;
	int		i;
	int		error_arg;

	exit_val = NULL;
	error_arg = 0;
	i = 0;
	if (tlst->next)
	{
		error_arg = ft_exit_error_arg(&tlst, &i);
		while (tlst->next->token->content[i]
			&& ft_isdigit(tlst->next->token->content[i]) == 1)
		{
			exit_val = ft_charjoin(exit_val, tlst->next->token->content[i]);
			i++;
		}
	}
	ft_putstr("exit\n");
	free_dlist(&g_mshell.env);
	free_tcmd(cmd);
	free_tlist(&tlst);
	clear_history();
	exit_number(error_arg, exit_val);
}

void	disp_synt_erro(char *str)
{
	printf("minishell: syntax error near unexpected token \'%s\'\n", str);
}

void	ft_error(char *str)
{
	printf(RED "%s\n" CRESET, str);
}
