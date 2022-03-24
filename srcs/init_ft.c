/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:38:48 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/24 10:38:57 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ft(t_tlist *tlst,  t_dlist **dupenv)
{
	char	*currcont;
	// pid_t	pi;

	currcont = tlst->token->content;
	if (ft_strcmp(currcont, "echo") == 0)
		ft_echo(tlst);
	else if (ft_strcmp(currcont, "cd") == 0)
		launch_cd(tlst, dupenv);
	else if (ft_strcmp(currcont, "env") == 0)
		ft_env(dupenv);
	else if (ft_strcmp(currcont, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(currcont, "unset") == 0)
		loop_unset(tlst, dupenv);
	else if (ft_strcmp(currcont, "export") == 0)
		loop_export(tlst, dupenv);
	// else if (ft_strcmp(currcont, "exit") == 0)
	// 	ft_echo(tlst);
	// else
	// {
	// 	pi = fork();
	// 	if (pi == 0)
	// 		execve();
	// }
}
