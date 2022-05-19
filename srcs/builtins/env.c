/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:39:30 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/19 13:22:24 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

t_dlist	*ft_dupenv(t_dlist *lst, char **envp)
{
	int		i;
	t_dlist	*new;

	i = 0;
	if (envp == NULL)
		return (NULL);
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

	if (!*dupenv)
		return ;
	curr = *dupenv;
	while (curr != NULL)
	{
		ft_putstr_fd(curr->content, 1);
		ft_putchar_fd('\n', 1);
		curr = curr->next;
	}
}
