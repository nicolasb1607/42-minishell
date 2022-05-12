/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:23:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/12 14:09:33 by ngobert          ###   ########.fr       */
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
	if (ret_line == NULL)
	{
		unlink_hd();
		printf(GRN"exit\n"CRESET);
		free_dlist(&g_mshell->env);
		clear_history();
		exit (0);
	}
	add_history(ret_line);
	return (ret_line);
}
