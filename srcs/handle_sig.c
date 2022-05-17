/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:22:54 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/17 10:22:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_sig.h"

void	free_dlist(t_dlist **dlist)
{
	t_dlist	*curr;
	t_dlist	*tmp;

	if (!dlist)
		return ;
	curr = *dlist;
	while (curr)
	{
		tmp = curr->next;
		free(curr->content);
		free(curr);
		curr = tmp;
	}
}

void	handler_main(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_mshell.err_exit = 130;
	}
}

void	handler_cmd(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		g_mshell.err_exit = 130;
	}
}

void	handler_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		exit(130);
	}
}

void	handle_quit(int signum)
{
	if (signum == SIGQUIT)
	{
		ft_putstr_fd("quit (core dumped)\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_mshell.err_exit = 131;
	}
}
