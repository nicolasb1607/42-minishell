/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:11:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 16:19:15 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_cleantlist(t_tlist *tlist)
{
	while (tlist)
	{
		if (!tlist->token->content)
		{
			ft_tlstdelone(tlist, free);
		}
		tlist = tlist->next;
	}
}

static void	init_tlist_loop(t_lexer *lexer, t_tlist **tlist,
	t_token **token, t_tlist **new)
{
	while (lexer->current_char != 0)
	{
		while (ft_iswhitespace(lexer->current_char) == 1)
			advance(lexer);
		(*token) = make_token(lexer);
		if (!(*token)->content)
			break ;
		(*new) = ft_tlstnew((*token));
		ft_tlstadd_back(tlist, *new);
	}
}

t_tlist	*init_tlist(char *str, t_tlist *tlist, t_minishell *mshell)
{
	t_tlist	*new;
	t_token	*token;
	t_lexer	lexer;
	int		i;

	i = 0;
	if (check_quote(str) == 0)
		return (NULL);
	init_lexer(&lexer, str);
	advance(&lexer);
	init_tlist_loop(&lexer, &tlist, &token, &new);
	ft_tlstiter(tlist, mshell, expandtok);
	while (i < 15)
	{
		ft_cleantlist(tlist);
		if (tlist && !tlist->token->content && tlist->next)
			tlist = tlist->next;
		i++;
	}
	g_mshell.err_exit = 0;
	return (tlist);
}
