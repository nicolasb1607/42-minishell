/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:25:44 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/23 11:15:36 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
	return (NULL);
}

void	close_fd(void)
{
	int	i;

	i = 3;
	while (i++ != FOPEN_MAX)
		close(i);
}

void	unlink_hd(void)
{
	int		i;
	char	*num;
	char	*file;

	i = INT_MIN;
	while (i != INT_MIN + 1000)
	{
		num = ft_itoa(i);
		file = ft_strjoin_free2("/tmp/.", num);
		if (access(file, F_OK) == 0)
			unlink(file);
		free(file);
		i++;
	}
	close_fd();
}

void	free_tcmd(t_cmd **cmd)
{
	t_cmd	*curr;
	t_cmd	*next;

	curr = *cmd;
	while (curr)
	{
		next = (free(curr->command), free(curr->bin), curr->next);
		ft_free_tab(curr->infile);
		if (curr->limiter)
			curr->limiter = ft_free_tab(curr->limiter);
		curr->options = (free(curr->type), ft_free_tab(curr->options));
		curr->outfile = ft_free_tab(curr->outfile);
		if (curr->builtin)
		{
			while (curr->builtin->prev)
				curr->builtin = curr->builtin->prev;
			while (curr->builtin)
				curr->builtin = (free(curr->builtin), curr->builtin->next);
		}
		curr = (free(curr), next);
	}
	*cmd = NULL;
	cmd = NULL;
}
