/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:23:32 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 17:24:58 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void
	ft_tlstiter(t_tlist *lst, t_minishell *mshell,
	void (*f)(t_token *, t_minishell *))
{
	t_tlist	*current;

	while (lst != NULL)
	{
		current = lst;
		lst = lst->next;
		f(current->token, mshell);
	}
}
