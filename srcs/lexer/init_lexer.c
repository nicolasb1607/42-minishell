/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:11:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/21 11:50:24 by nburat-d         ###   ########.fr       */
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
	while (lexer.current_char != 0)
	{
		while (ft_iswhitespace(lexer.current_char) == 1)
			advance(&lexer);
		token = make_token(&lexer);
		if (!token->content)
			break ;
		new = ft_tlstnew(token);
		ft_tlstadd_back(&tlist, new);
	}
	ft_tlstiter(tlist, mshell, expandtok);
	while (i < 15)
	{
		ft_cleantlist(tlist);
		if (tlist && !tlist->token->content && tlist->next)
			tlist = tlist->next; // ! Peut etre un free a regler avec celui d'avant
		i++;
	}
	g_mshell.err_exit = 0;
	return (tlist);
}
