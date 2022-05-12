/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cmdlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:27 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/02 10:30:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*create_tmp(void)
{
	int		i;
	char	*str;

	i = INT_MIN;
	while (i < INT_MAX)
	{
		str = ft_itoa(i);
		str = ft_strjoin("/tmp/.", str);
		if (access(str, F_OK) != 0)
			return (str);
		free(str);
		i++;
	}
	return (NULL);
}






void	update_io(t_cmd *cmd, t_tlist *lst, int ret)
{
	char	*file_name;

	lst = lst->next;
	if (ret == 1)
	{
		cmd->outfile = ft_tab_addback(cmd->outfile, lst->token->content);
		cmd->is_double = false;
	}
	else if (ret == 2)
	{
		file_name = ft_strdup(lst->token->content);
		if (file_name[ft_strlen(file_name) - 1] == ' ')
			file_name = ft_strndup(file_name, ft_strlen(file_name) - 1);
		if (!access(file_name, F_OK))
			cmd->infile = ft_tab_addback(cmd->infile, file_name);
		else
			ft_error("Cant open infile");
		cmd->is_double = false;
		free(file_name);
	}
	else if (ret == 3)
	{
		file_name = ft_strdup(lst->token->content);
		cmd->outfile = ft_tab_addback(cmd->outfile, file_name);
		cmd->is_double = (free(file_name), true);
	}
	else if (ret == 4)
	{
		cmd->limiter = ft_tab_addback(cmd->limiter, lst->token->content);
		cmd->infile = ft_tab_addback(cmd->infile, create_tmp());
		cmd->is_double = true;
		make_heredoc(cmd);
	}
}

t_cmd	*tlst_to_cmd(t_tlist **tlst)
{
	char	*opt;
	t_tlist	*curr;
	t_cmd	*cmd;
	int		quote;
	int		i;

	quote = 0;
	i = 0;
	curr = *tlst;
	opt = NULL;
	cmd = ft_clstnew();
	while (curr && ft_strcmp(curr->token->type, T_PIPE) != 0)
	{
		if (curr && is_operator(curr->token->type) == 0 && i == 0)
			cmd->command = (i++, ft_strdup(curr->token->content));
		while (curr && is_redir(curr->token->type) != 0)
		{
			update_io(cmd, curr, is_redir(curr->token->type));
			if (g_mshell.err_exit == 130)
				break ;
			curr = curr->next->next;
		}
		if (curr && is_operator(curr->token->type) == 0)
		{
			if (i == 0)
				cmd->command = (i++, ft_strdup(curr->token->content));
			if (quote == 0 && curr->token->quote)
			{
				quote = 1;
				opt = ft_strjoin_free(opt, "\"");
			}
			opt = ft_strjoin_free(opt, curr->token->content);
			if (quote == 1)
			{
				quote = 0;
				opt = ft_strjoin_free(opt, "\"");
			}
			opt = ft_strjoin_free(opt, " ");
		}
		else
			break ;
		curr = curr->next;
	}
	*tlst = curr;
	cmd->options = ft_split_custom(opt, ' ');
	if (!cmd->infile)
	{
		cmd->infile = ft_tab_addback(cmd->infile, STDIN);
		cmd->update_i = false;
	}
	else
		cmd->update_i = true;
	if (!cmd->outfile)
	{
		cmd->outfile = ft_tab_addback(cmd->outfile, "/dev/stdout");
		cmd->update_o = false;
	}
	else
		cmd->update_o = true;
	free(opt);
	return (cmd);
}


