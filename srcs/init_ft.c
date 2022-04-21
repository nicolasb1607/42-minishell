/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:14:39 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/21 14:56:01 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtincmd(t_cmd *cmd)
{
	char	*currcont;

	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0)
		return (1);
	else
		return (0);
}

int	is_forkbuiltin(t_cmd *cmd)
{
	char	*currcont;

	currcont = cmd->command;
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0 && !cmd->options[1])
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
	char **path;
	t_cmd *cmd;
	pid_t pi;
	t_tlist *curr;
	t_pipes	pipes;

	curr = tlst;
	if (tlst->token->content)
	{
		while (tlst)
		{
			curr = tlst;
			cmd = tlst_to_cmd(&tlst);
			path = get_path_to_cmd(curr, dupenv);
			if(update_bin(path, cmd, curr) == -1)
			{
				g_mshell.err_exit = 127;
				return ;
			}
			ft_clstadd_back(&chead, cmd);
			if (tlst)
				tlst = tlst->next;
		}
		open_io(chead, &pipes);

		//! Ajout de la gestion des signaux
		if (ft_strncmp(chead->command,"./minishell", 12) == 0)
			signal(SIGINT, SIG_IGN);
		else
			signal(SIGINT, handler_cmd);
		signal(SIGQUIT, SIG_IGN);
		if (is_builtincmd(cmd))
		{
			while (ft_strcmp(curr->token->content, cmd->command) != 0)
				curr = curr->next;
			if (is_forkbuiltin(cmd))
			{
				pi = fork();
				if (pi == 0)
				{
					dup2(pipes.fd_out, STDOUT_FILENO);
					dup2(pipes.fd_in, STDIN_FILENO);
					exec_builtin(curr, dupenv);
					exit(EXIT_SUCCESS);
				}
			}
			else
				exec_builtin(curr, dupenv);
		}
		else if ((chead)->is_absolute)
		{
			pi = fork();
			if (pi == 0)
			{
				dup2(pipes.fd_out, STDOUT_FILENO);
				dup2(pipes.fd_in, STDIN_FILENO);
				execve((chead)->command, (chead)->options, dlist_to_tab(*dupenv));
			}
		}
		else
		{
			pi = fork();
			if (pi == 0)
			{
				dup2(pipes.fd_out, STDOUT_FILENO);
				dup2(pipes.fd_in, STDIN_FILENO);
				execve((chead)->bin, (chead)->options, dlist_to_tab(*dupenv));
			}
		}
		// print_t_cmd(chead);
		waitpid(pi, NULL, 0);
//! Ajout de la fonction de gestion d erreur 
		// free(chead);
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
	if (ft_strncmp(currcont, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(currcont, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(currcont, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(currcont, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(currcont, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(currcont, "exit", 5) == 0)
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
	t_cmd *cmd;
	t_tlist *curr;

	nb_cmd = count_command(tlst);
	if (tlst->token->content)
	{
		while (tlst)
		{
			curr = tlst;
			if (!is_builtin(curr))
			{
				cmd = tlst_to_cmd(&tlst);
				path = get_path_to_cmd(curr, dupenv);
				if(update_bin(path, cmd, curr) == -1)
				{
					g_mshell.err_exit = 127;
					return ;
				}
				cmd->is_builtin = false;
			}
			else
			{
				cmd = ft_clstnew();
				cmd->builtin = NULL;
				cpy_till_pipe(&tlst, &cmd->builtin);
				if (!cmd->infile)
				{
					cmd->infile = STDIN;
					cmd->update_i = false;
				}
				if (!cmd->outfile)
				{
					cmd->outfile = ft_tab_addback(cmd->outfile, STDOUT);
					cmd->update_o = false;
				}
			}
			if (tlst)
					tlst = tlst->next;
			ft_clstadd_back(&chead, cmd);
		}
		piping(nb_cmd, chead, dupenv, tlst);	
	}
}
 