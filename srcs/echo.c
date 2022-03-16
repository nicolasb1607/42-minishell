/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:09 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/16 11:31:07 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

int	__is_valid_option(t_tlist *tlst)
{
	int	i;

	if (tlst->token->content[0] == '-')
	{
		i = 1;
		while (tlst->token->content[i])
		{
			if (tlst->token->content[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_echo(t_tlist *tlst)
{
	t_tlist	*curr;
	int		nl_opt;

	curr = tlst->next;
	nl_opt = 0;
	while (__is_valid_option(curr) == 1)
	{
		nl_opt = 1;
		curr = curr->next;
	}
	while (curr && __is_type(curr, T_STRING))
	{
		ft_putstr(curr->token->content);
		if (curr->next && curr->token->space_after == 1)
			ft_putchar(' ');
		curr = curr->next;
	}
	if (nl_opt == 0)
		ft_putchar('\n');
}
