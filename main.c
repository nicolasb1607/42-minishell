/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:51:32 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/12 15:10:33 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "structs.h"

t_minishell	g_mshell;

static void	launch_cmd(t_tlist **tlist)
{
	if (count_command((*tlist)) == 1 && (ft_tlstsize((*tlist)) != 0
			&& ft_strlen((*tlist)->token->content) != 0))
		only1cmd((*tlist), &g_mshell.env, g_mshell.cmd);
	else if (count_command((*tlist)) > 1)
		init_ft((*tlist), &g_mshell.env, g_mshell.cmd);
	free_tlist(&(*tlist));
	free_tcmd(&g_mshell.cmd);
	g_mshell.cmd = NULL;
}

static void	launch_cmd2(t_tlist **tlist, char **ret)
{
	(*tlist) = init_tlist(*ret, (*tlist), &g_mshell);
	if ((*tlist))
	{
		if (parser((*tlist)))
			launch_cmd(tlist);
		else
			free_tlist(tlist);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_tlist	*tlist;
	char	*ret;

	(void)ac;
	(void)av;
	tlist = NULL;
	g_mshell.env = NULL;
	g_mshell.env = ft_dupenv(g_mshell.env, envp);
	while (1)
	{
		signal(SIGINT, handler_main);
		signal(SIGQUIT, SIG_IGN);
		ret = ft_prompt(&g_mshell);
		if (ft_strlen(ret) != 0)
			launch_cmd2(&tlist, &ret);
		close_fd();
	}
	exit (0);
}
