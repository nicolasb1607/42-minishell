/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:23:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/20 11:22:53 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*ft_strsub(char *str, int to_sub, int len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (char *)cmalloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = str[to_sub + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_prompt(t_minishell *g_mshell)
{
	char	*ret_line;

	ret_line = readline(BCYN"Minishell $> "CRESET);
	if (!ret_line)
	{
		unlink_hd();
		ft_printf(GRN"exit\n"CRESET);
		free_dlist(&g_mshell->env);
		rl_clear_history();
		exit (0);
	}
	add_history(ret_line);
	return (ret_line);
}
