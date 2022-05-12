/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlst_to_cmd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:00:40 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/12 13:36:30 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	tlst_to_cmd_loop1(t_tlist **curr, t_cmd **cmd, t_dlist **dupenv)
{
	while ((*curr) && is_redir((*curr)->token->type) != 0)
	{
		update_io((*cmd), (*curr), is_redir((*curr)->token->type), dupenv);
		if (g_mshell.err_exit == 130)
			break ;
		(*curr) = (*curr)->next->next;
	}
}

static void	tlst_to_cmd_cond1(int *i, t_tlist **curr, char **opt, t_cmd **cmd)
{
	int	quote;

	quote = 0;
	if (*i == 0)
		(*cmd)->command = ((*i)++, ft_strdup((*curr)->token->content));
	if (quote == 0 && (*curr)->token->quote)
	{
		quote = 1;
		*opt = ft_strjoin_free(*opt, "\"");
	}
	*opt = ft_strjoin_free(*opt, (*curr)->token->content);
	if (quote == 1)
	{
		quote = 0;
		*opt = ft_strjoin_free(*opt, "\"");
	}
	*opt = ft_strjoin_free(*opt, " ");
}

static void	tlst_to_cmd_cond2(t_cmd **cmd)
{
	if (!(*cmd)->infile)
	{
		(*cmd)->infile = ft_tab_addback((*cmd)->infile, STDIN);
		(*cmd)->update_i = false;
	}
	else
		(*cmd)->update_i = true;
	if (!(*cmd)->outfile)
	{
		(*cmd)->outfile = ft_tab_addback((*cmd)->outfile, "/dev/stdout");
		(*cmd)->update_o = false;
	}
	else
		(*cmd)->update_o = true;
}

t_cmd	*tlst_to_cmd(t_tlist **tlst, t_dlist **dupenv)
{
	char	*opt;
	t_tlist	*curr;
	t_cmd	*cmd;
	int		i;

	i = 0;
	curr = *tlst;
	opt = NULL;
	cmd = ft_clstnew();
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		if (curr && is_operator(curr->token->type) == 0 && i == 0)
			cmd->command = (i++, ft_strdup(curr->token->content));
		tlst_to_cmd_loop1(&curr, &cmd, dupenv);
		if (curr && is_operator(curr->token->type) == 0)
			tlst_to_cmd_cond1(&i, &curr, &opt, &cmd);
		else
			break ;
		curr = curr->next;
	}
	*tlst = curr;
	cmd->options = ft_split_custom(opt, ' ');
	i = (tlst_to_cmd_cond2(&cmd), free(opt), 0);
	return (cmd);
}
