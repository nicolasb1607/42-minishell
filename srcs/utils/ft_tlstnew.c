/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:15:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/04 16:59:52 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tlist	*ft_tlstnew(t_token *tok)
{	
	t_tlist	*node;
	
	node->token = NULL;
	node = malloc(sizeof(t_tlist));
	if (!node)
		return (NULL);
	node->token->content = tok->content;
	node->token->quote = tok->quote;
	node->token->type = tok->type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
