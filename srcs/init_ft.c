/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:04:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/16 14:29:24 by nburat-d         ###   ########.fr       */
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
	if (ft_strcmp(currcont, "cd") == 0)
		launch_cd(tlst, dupenv);
	if (ft_strcmp(currcont, "env") == 0)
		ft_env(dupenv);
	if (ft_strcmp(currcont, "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(currcont, "unset") == 0)
		loop_unset(tlst, dupenv);
	if (ft_strcmp(currcont, "export") == 0)
		loop_export(tlst, dupenv);
	// if (ft_strcmp(currcont, "exit") == 0)
	// 	ft_echo(tlst);
	// else
	// {
	// 	pi = fork();
	// 	if (pi == 0)
	// 		execve();
	// }
}
