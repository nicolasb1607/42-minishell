/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:39:30 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/04 13:05:57 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_dlist	*ft_dupenv(t_dlist *lst, char **envp)
{
	int		i;
	t_dlist	*new;

	i = 0;
	while (envp[i])
	{
		new = ft_dlstnew(ft_strdup(envp[i]));
		ft_dlstadd_back(&lst, new);
		i++;
	}
	return (lst);
}

void	ft_env(t_dlist **dupenv)
{
	t_dlist	*curr;

	curr = *dupenv;
	while (curr != NULL)
	{
		ft_putstr(curr->content);
		ft_putchar('\n');
		curr = curr->next;
	}
}
