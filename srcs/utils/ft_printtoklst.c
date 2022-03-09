/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtoklst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 17:50:11 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utils.h"

void	ft_printtoklst(t_tlist *tlist)
{
	t_tlist	*curr;

	curr = tlist;
	while (curr)
	{
		if (curr->token->content)
		{
			ft_putstr(curr->token->type);
			ft_putchar('\t');
			ft_putstr(curr->token->content);
			ft_putchar('\n');
		}
		curr = curr->next;
	}
}
