/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:37:24 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/30 14:16:14 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

int	__is_valid_option(char *content)
{
	int	i;

	if (content[0] == '-' && ft_containchar('n', content) == 1)
	{
		i = 1;
		while (content[i])
		{
			if (content[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	split_first_tok_arg(t_tlist *tlst, int *nl_opt)
{
	char	**splittedtok;
	int		i;

	i = -1;
	splittedtok = ft_split(tlst->token->content, ' ');
	if (splittedtok[1])
	{
		i = 1;
		while (__is_valid_option(splittedtok[i]) && splittedtok[i])
		{
			*nl_opt = 1;
			i++;
		}
		while (splittedtok[i])
		{
			ft_putstr(splittedtok[i++]);
			ft_putchar(' ');
		}
	}
}


void	checktype(t_tlist *curr)
{
	int	i;
	int space;

	i = 0;
	space = 0;
	if (curr->token->quote)
		ft_putstr(curr->token->content);
	else
	{
		while(curr->token->content[i])
		{
			if(curr->token->content[i] != ' ')
			{
				ft_putchar(curr->token->content[i]);
				space = 0;
			}
			else if (curr->token->content[i] == ' ' && space == 0)
			{
				ft_putchar(' ');
				space = 1;
			}
			i++;	
		}
	}
}

void	ft_echo(t_tlist *tlst)
{
	t_tlist	*curr;
	int		nl_opt;

	nl_opt = 0;
	split_first_tok_arg(tlst, &nl_opt);
	curr = tlst->next;
	if (curr && curr->token->content[0] == '-'
		&& ft_strlen(curr->token->content) == 1)
		curr = curr->next;
	while (curr && __is_valid_option(curr->token->content) == 1)
	{
		nl_opt = 1;
		curr = curr->next;
	}
	while (curr && __is_type(curr, T_STRING))
	{
		checktype(curr);
		if (curr->next && curr->token->space_after == 1)
			ft_putchar(' ');
		curr = curr->next;
	}
	if (nl_opt == 0)
		ft_putchar('\n');
}
