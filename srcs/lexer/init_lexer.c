/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:11:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/29 13:14:00 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_cleantlist(t_tlist *tlist)
{
	while (tlist->next)
	{
		if (tlist->token->content && tlist->next)
			tlist = tlist->next;
		if (!tlist->token->content)
		{
			ft_tlstdelone(tlist, free);
			tlist = tlist->prev;
		}
	}
}

t_tlist	*init_tlist(char *str, t_tlist *tlist, t_minishell *mshell)
{
	t_tlist	*new;
	t_token	*token;
	t_lexer	lexer;

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
	ft_cleantlist(tlist);
	return (tlist);
}
