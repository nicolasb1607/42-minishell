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

char **ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (!tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void only1cmd(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	char *currcont;
	pid_t pi;
	char **tabenv;
	char **path;
	t_cmd *cmd;
	t_tlist *curr;

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
			while (tlst)
			{
				curr = tlst;
				cmd = tlst_to_cmd(&tlst);
				path = get_path_to_cmd(curr, dupenv);
				update_bin(path, cmd, curr);
				ft_clstadd_back(&chead, cmd);
				if (tlst)
					tlst = tlst->next;
			}
			tabenv = dlist_to_tab(*dupenv);
			if ((chead)->is_absolute/* && path*/)
			{
				pi = fork();
				if (pi == 0)
				{
					execve((chead)->command, (chead)->options, tabenv);
				}
			}
			else
			{
				pi = fork();
				if (pi == 0)
				{
					execve((chead)->bin, (chead)->options, tabenv);
				}
			}
			waitpid(pi, NULL, 0);
			// free(chead);
		}
	}
}

void	free_tcmd(t_cmd **cmd)
{
	t_cmd *curr;
	t_cmd *next;

	curr = *cmd;
	while (curr)
	{
		if (curr->next)
			next = curr->next;
		free(curr->command);
		free(curr->bin);
		curr->options = ft_free_tab(curr->options);
		curr->outfile = ft_free_tab(curr->outfile);
		free(curr);
		curr = next;
	}
	*cmd = NULL;
	cmd = NULL;
}

void	init_ft(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	char *currcont;
	pid_t pi;
	char **tabenv;
	char **path;

	t_cmd *cmd;

	t_tlist *curr;

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
			while (tlst)
			{
				curr = tlst;
				cmd = tlst_to_cmd(&tlst);
				path = get_path_to_cmd(curr, dupenv);
				update_bin(path, cmd, curr);
				ft_clstadd_back(&chead, cmd);
				if (tlst)
					tlst = tlst->next;
			}
			tabenv = dlist_to_tab(*dupenv);
			while (chead)
			{
				if ((chead)->is_absolute)
				{
					pi = fork();
				
					if (pi == 0)
					{
						execve((chead)->command, (chead)->options, tabenv);
					}
				}
				else
				{
					pi = fork();
					if (pi == 0)
					{
						execve((chead)->bin, (chead)->options, tabenv);
					}
				}
				waitpid(pi, NULL, 0);
				chead = chead->next;
			}
		}
	}
}
