/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:35:42 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/10 14:10:08 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	count_command(t_tlist *tlst)
{
	int		count;
	t_tlist	*curr;

	count = 0;
	curr = tlst;
	while (curr)
	{
		if (ft_strcmp(curr->token->type, T_PIPE) == 0)
			count++;
		curr = curr->next;
	}
	return (count + 1);
}
