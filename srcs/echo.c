/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:09 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/11 15:15:25 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

void	ft_echo(t_tlist *tlst)
{
	t_tlist *curr;
	int	nl_opt;
	
	curr = tlst->next;
	nl_opt = 0;
	printf("curr token = %s\n", curr->token->content);
	if (ft_strncmp(curr->token->content, "-n", ft_strlen(curr->token->content)) == 0)
	{
		printf("MAJ de nl_opt\n");
		nl_opt = 1;
		curr = curr->next;
	}
	printf("nlopt = %d\n", nl_opt);
	while (curr && __is_type(curr, T_STRING))
	{
		ft_putstr(curr->token->content);
		ft_putchar(' ');
		curr = curr->next;
	}
	if (nl_opt == 0)
		ft_putchar('\n');
}
