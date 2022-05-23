/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:33:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/23 14:34:03 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	exec_builtin_exit(t_tlist **builtin, t_cmd **cmd)
{
	if (!check_all_al((*cmd)->options)
		&& ((*cmd)->options[1] && (*cmd)->options[2]))
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_mshell.err_exit = 1;
		return ;
	}
	else
	{
		free_tlist(builtin);
		ft_exit(cmd);
	}
}
