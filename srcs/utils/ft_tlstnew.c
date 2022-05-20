/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:15:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/20 11:23:33 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tlist	*ft_tlstnew(t_token *token)
{	
	t_tlist	*node;

	node = cmalloc(sizeof(t_tlist));
	if (!node)
		return (NULL);
	node->token = token;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
