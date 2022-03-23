/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:09 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/23 16:39:555 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

int	__is_valid_option(t_tlist *tlst)
{
	int	i;

	if (tlst->token->content[0] == '-' && ft_containchar('n', tlst->token->content) == 1)
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

void	print_rest_tok(char *str, t_tlist *tlst)
{
	int	i;
	char **splitted_tok;

	i = 0;
	splitted_tok = ft_split(str, ' ');

	while (splitted_tok[i])
	{
		printf("splittedtok = %s\n", splitted_tok[i]);
		i++;
	}
	
	i = ft_tablen(splitted_tok);
	printf("i = %d\n", i);
	while (i > 1)
	{
		ft_tlstaddpos(tlst, splitted_tok[i], 2);
		i--;
	}
}

void	ft_echo(t_tlist *tlst)
{
	t_tlist	*curr;
	int		nl_opt;

	print_rest_tok(tlst->token->content, tlst);
	curr = tlst->next;
	nl_opt = 0;
	if (curr && curr->token->content[0] == '-' && ft_strlen(curr->token->content) == 1)
		curr = curr->next;	
	while (curr && __is_valid_option(curr) == 1)
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
