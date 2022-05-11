/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft_mkcmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:48:08 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/11 17:23:53 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mpipe.h"

t_cmd
	*make_commands(t_tlist *tlst, t_cmd **chead,
	t_dlist **dupenv, t_tlist *curr)
{
	t_cmd	*cmd;
	char	**path;

	while (tlst)
	{
		curr = (tlst);
		cmd = tlst_to_cmd(&tlst);
		path = get_path_to_cmd(dupenv);
		if (update_bin(path, cmd, curr) == -1)
		{
			path = (ft_free_tab(path), free_tcmd(chead), free_tcmd(&cmd), NULL);
			if (g_mshell.err_exit != 130)
				g_mshell.err_exit = 127;
			return (NULL);
		}
		path = ft_free_tab(path);
		ft_clstadd_back(chead, cmd);
		if (tlst)
			(tlst) = (tlst)->next;
	}
	return (cmd);
}

t_cmd	*mk_built(t_tlist **tlst)
{
	t_cmd	*cmd;
	t_tlist	*tmp;

	tmp = (*tlst);
	cmd = tlst_to_cmd(&tmp);
	tmp = (*tlst);
	cmd->builtin = NULL;
	cpy_till_pipe(tlst, &cmd->builtin);
	return (cmd);
}

t_cmd
	*mk_cmd_b(t_tlist **tlst, t_dlist **dupenv, t_cmd *chead, t_tlist **curr)
{
	t_cmd	*cmd;
	char	**path;

	cmd = tlst_to_cmd(tlst);
	path = get_path_to_cmd(dupenv);
	if (update_bin(path, cmd, *curr) == -1)
	{
		path = (ft_free_tab(path), free_tcmd(&chead), free_tcmd(&cmd), NULL);
		if (g_mshell.err_exit != 130)
			g_mshell.err_exit = 127;
		return (NULL);
	}
	cmd->is_builtin = (ft_free_tab(path), false);
	return (cmd);
}

void	sig_norm(t_pipes *pipes, t_cmd **chead)
{
	open_io(*chead, pipes);
	if (ft_strcmp((*chead)->command, "./minishell") == 0)
		signal(SIGINT, SIG_IGN);
	else
		signal(SIGINT, handler_cmd);
	signal(SIGQUIT, SIG_IGN);
}
