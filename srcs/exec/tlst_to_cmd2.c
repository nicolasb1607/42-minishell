/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlst_to_cmd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:41 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 11:42:32 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	tlst_to_cmd_condition1(t_cmd **cmd, t_tlist **curr,
	int *i, char **opt)
{
	int	quote;

	quote = 0;
	if (i == 0)
	{
		i++;
		(*cmd)->command = ft_strdup((*curr)->token->content);
	}
	if (quote == 0 && (*curr)->token->quote)
	{
		quote = 1;
		(*opt) = ft_strjoin_free((*opt), "\"");
	}
	(*opt) = ft_strjoin_free((*opt), (*curr)->token->content);
	if (quote == 1)
	{
		quote = 0;
		(*opt) = ft_strjoin_free((*opt), "\"");
	}
	(*opt) = ft_strjoin_free((*opt), " ");
}

static void	tlst_to_cmd_condition2(t_cmd **cmd)
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

static void	tlst_to_cmd_loop(t_tlist **curr, t_cmd **cmd, int *i, char **opt)
{
	while ((*curr) && ft_strcmp((*curr)->token->type, T_PIPE) != 0)
	{
		if ((*curr) && is_operator((*curr)->token->type) == 0 && *i == 0)
		{
			*i = *i + 1;
			(*cmd)->command = ft_strdup((*curr)->token->content);
		}
		while ((*curr) && is_redir((*curr)->token->type) != 0)
		{
			update_io((*cmd), (*curr), is_redir((*curr)->token->type));
			if (g_mshell.err_exit == 130)
				break ;
			(*curr) = (*curr)->next->next;
		}
		if ((*curr) && is_operator((*curr)->token->type) == 0)
			tlst_to_cmd_condition1(cmd, curr, i, opt);
		else
			break ;
		(*curr) = (*curr)->next;
	}
}

t_cmd	*tlst_to_cmd(t_tlist **tlst)
{
	char	*opt;
	t_tlist	*curr;
	t_cmd	*cmd;
	int		i;

	i = 0;
	curr = *tlst;
	opt = NULL;
	cmd = ft_clstnew();
	tlst_to_cmd_loop(&curr, &cmd, &i, &opt);
	*tlst = curr;
	cmd->options = ft_split_custom(opt, ' ');
	tlst_to_cmd_condition2(&cmd);
	free(opt);
	return (cmd);
}
