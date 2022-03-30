/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:38:48 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/30 10:34:07 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ft(t_tlist *tlst,  t_dlist **dupenv)
{
	char	*currcont;
	pid_t	pi;
	char	**tabenv;
	char	**path;
	t_cmd	*cmd;

	currcont = tlst->token->content;
	if (ft_strcmp(currcont, "echo ") == 0)
		ft_echo(tlst);
	else if (ft_strcmp(currcont, "cd ") == 0)
		launch_cd(tlst, dupenv);
	else if (ft_strcmp(currcont, "env ") == 0)
		ft_env(dupenv);
	else if (ft_strcmp(currcont, "pwd ") == 0)
		ft_pwd();
	else if (ft_strcmp(currcont, "unset ") == 0)
		loop_unset(tlst, dupenv);
	else if (ft_strcmp(currcont, "export ") == 0)
		loop_export(tlst, dupenv);
	// else if (ft_strcmp(currcont, "exit") == 0)
		// ft_echo(tlst);
	else
	{
		cmd = tlst_to_cmd(tlst);
		path = get_path_to_cmd(tlst, dupenv);
		update_bin(path, cmd);
		tabenv = dlist_to_tab(*dupenv);
		
		if (cmd->is_absolute)
		{
			pi = fork();
			if (pi == 0)
			{
				execve(cmd->command, cmd->options, tabenv);
			}
		}
		else
		{
			pi = fork();
			if (pi == 0)
			{
				execve(cmd->bin, cmd->options, tabenv);
			}
		}
		waitpid(pi, NULL, 0);
	}
}
