/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:23:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/16 20:23:37 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*ft_strsub(char *str, int to_sub, int len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
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

	ret_line = readline(BLU"Minishell$> "CRESET);
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
