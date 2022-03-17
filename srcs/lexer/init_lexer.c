/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:11:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/17 14:57:58 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
	//(void) mshell;
	ft_tlstiter(tlist, mshell, expandtok);
	return (tlist);
}
