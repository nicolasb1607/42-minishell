/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:38:48 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/01 16:04:444 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_ft(t_tlist *tlst, t_dlist **dupenv)
{
	char *currcont;
	pid_t pi;
	char **tabenv;
	char **path;
	t_cmd *cmd;

	if (tlst->token->content)
	{
		currcont = tlst->token->content;
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
		else
		{
			printf("AVnt tlst to cmd\n");
			cmd = tlst_to_cmd(tlst);
			printf("AVnt get path to cmd\n");
			path = get_path_to_cmd(tlst, dupenv);
			update_bin(path, cmd, tlst);
			tabenv = dlist_to_tab(*dupenv);

			if (cmd->is_absolute && path)
			{
				pi = fork();
				if (pi == 0)
				{
					printf("AVnt execve\n");
					execve(cmd->command, cmd->options, tabenv);
				}
			}
			else
			{
				pi = fork();
				if (pi == 0)
				{
					printf("AVnt execve\n");
					execve(cmd->bin, cmd->options, tabenv);
				}
			}
			waitpid(pi, NULL, 0);
		}
	}
}
