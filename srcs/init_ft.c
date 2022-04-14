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

int	is_builtincmd(t_cmd *cmd)
{
	char	*currcont;

	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo ", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd ", 2) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env ", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd ", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset ", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export ", 6) == 0)
		return (1);
	else
		return (0);
}

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
	char **tabenv;
	char **path;
	t_cmd *cmd;
	pid_t pi;
	t_tlist *curr;

	curr = tlst;
	if (tlst->token->content)
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
		if (is_builtincmd(cmd))
		{
			while (ft_strcmp(curr->token->content, cmd->command) != 0)
				curr = curr->next;
			exec_builtin(curr, dupenv);
		}
		else if ((chead)->is_absolute)
		{
			if (ft_strcmp(chead->command, "./minishell") == 0)
					signal(SIGINT, SIG_IGN);
			pi = fork();
			if (pi == 0)
				execve((chead)->command, (chead)->options, tabenv);
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
		// print_t_cmd(chead);
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

int	is_builtin(t_tlist *lst)
{
	char	*currcont;

	currcont = lst->token->content;
	if (ft_strncmp(currcont, "echo ", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd ", 2) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env ", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd ", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset ", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export ", 6) == 0)
		return (1);
	else
		return (0);
}


void	cpy_till_pipe(t_tlist **tlist, t_tlist **tlistnew)
{
	t_tlist *curr;
	t_tlist *new;

	curr = *tlist;
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		new = ft_tlstnew(curr->token);
		ft_tlstadd_back(tlistnew, new);
		curr = curr->next;
	}
	*tlist = curr;
}


void	init_ft(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead)
{
	char	**path;
	int		nb_cmd;

	nb_cmd = count_command(tlst);

	t_cmd *cmd;

	t_tlist *curr;

	if (tlst->token->content)
	{
		while (tlst)
		{
			curr = tlst;
			if (!is_builtin(curr))
			{
				cmd = tlst_to_cmd(&tlst);
				path = get_path_to_cmd(curr, dupenv);
				update_bin(path, cmd, curr);
				cmd->is_builtin = false;
			}
			else
			{
				cmd = ft_clstnew();
				cmd->builtin = NULL;
				cpy_till_pipe(&tlst, &cmd->builtin);
				if (!cmd->infile)
					cmd->infile = STDIN;
				if (!cmd->outfile)
					cmd->outfile = ft_tab_addback(cmd->outfile, STDOUT);
				// ft_printtoklst(cmd->builtin);
			}
			if (tlst)
					tlst = tlst->next;
			ft_clstadd_back(&chead, cmd);
		}
		// print_t_cmd(chead);
		piping(nb_cmd, chead, dupenv, tlst);	
	}
}
 