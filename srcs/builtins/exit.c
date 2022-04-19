/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:08 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/15 15:46:32 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	ft_exit(void)
{
	printf(GRN"exit\n"CRESET);
	free_dlist(g_mshell.env);
	clear_history();	
	exit (0);
}

void	disp_synt_erro(char *str)
{
	printf(RED"minishell: syntax error near unexpected token \'%s\'\n"CRESET, str);
}

void	ft_error(char *str)
{
	printf(RED"%s\n"CRESET, str);
}