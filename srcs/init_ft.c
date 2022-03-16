/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:04:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/16 13:27:47 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ft(t_tlist *tlst)
{
	char	*currcont;
	pid_t	pi;

	currcont = tlst->token->content;
	
	if (ft_strcmp(currcont, "echo") == 0)
		ft_echo(tlst);

	else
	{
		pi = fork();
		if (pi == 0)
			execve();
	}
}
