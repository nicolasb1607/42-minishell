/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:08 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/22 14:44:45 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	ft_exit(t_tlist *tlst)
{
	char *exit_val;
	int i;

	exit_val = NULL;
	i = 0;
	if(tlst->next)
	{
		if (ft_isdigit(tlst->next->token->content[i]) == 0)
		{
			ft_putstr("minishell: exit: tests: numeric argument required\n");
			g_mshell.err_exit = 2;
			return ;
		}
		while(tlst->next->token->content[i] && ft_isdigit(tlst->next->token->content[i]) == 1)
		{
			exit_val = ft_charjoin(exit_val, tlst->next->token->content[i]);
			i++;
		}
	}
	printf(GRN"exit\n"CRESET);
	free_dlist(g_mshell.env);
	clear_history();	
	if (exit_val == NULL)
		exit(0);
	else
		exit(ft_atoi(exit_val));

}

void	disp_synt_erro(char *str)
{
	printf(RED"minishell: syntax error near unexpected token \'%s\'\n"CRESET, str);
}

void	ft_error(char *str)
{
	printf(RED"%s\n"CRESET, str);
}