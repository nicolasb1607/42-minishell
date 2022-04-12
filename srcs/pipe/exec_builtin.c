/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:23:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/12 11:45:56 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	exec_builtin(t_cmd *cmd, t_pipes *pipes)
{
	char	*currcont;
	t_dlist	**dupenv;
	t_tlist	*tlst;

	dupenv = pipes->denv;
	tlst = pipes->tlst;
	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo ", 4) == 0)
		ft_echo(tlst);
	else if (ft_strncmp(currcont, "cd ", 2) == 0)
		launch_cd(tlst, dupenv);
	else if (ft_strncmp(currcont, "env ", 3) == 0)
		ft_env(dupenv);
	else if (ft_strncmp(currcont, "pwd ", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(currcont, "unset ", 5) == 0)
		loop_unset(tlst, dupenv);
	else if (ft_strncmp(currcont, "export ", 6) == 0)
		loop_export(tlst, dupenv);
}