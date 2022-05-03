/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:08 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/03 10:41:13 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	ft_exit(t_tlist *tlst, t_cmd **cmd)
{
	char *exit_val;
	int i;
	int error_arg;

	exit_val = NULL;
	error_arg = 0;
	i = 0;
	if(tlst->next)
	{
		if (ft_isdigit(tlst->next->token->content[i]) == 0)
		{
			printf("minishell: exit: %s: numeric argument required\n", tlst->next->token->content);
			error_arg = 1;
		}
		while(tlst->next->token->content[i] && ft_isdigit(tlst->next->token->content[i]) == 1)
		{
			exit_val = ft_charjoin(exit_val, tlst->next->token->content[i]);
			i++;
		}
	}
	printf(GRN"exit\n"CRESET);
	free_dlist(&g_mshell.env);
	free_tcmd(cmd);
	free_tlist(&tlst);
	clear_history();
	if (error_arg == 1)
		exit(2);	
	if (exit_val == NULL)
		exit(0);
	else
		exit(ft_atoi(exit_val) % 256);

}

void	disp_synt_erro(char *str)
{
	printf(RED"minishell: syntax error near unexpected token \'%s\'\n"CRESET, str);
}

void	ft_error(char *str)
{
	printf(RED"%s\n"CRESET, str);
}