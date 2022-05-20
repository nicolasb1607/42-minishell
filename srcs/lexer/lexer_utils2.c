/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:37:45 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/20 11:23:02 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*init_token(void)
{
	t_token	*token;

	token = cmalloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = NULL;
	token->type = NULL;
	token->quote = NULL;
	token->space_after = 1;
	return (token);
}

void	assign_toks(t_token *token, char *content, char *type)
{
	token->content = content;
	token->type = type;
}
