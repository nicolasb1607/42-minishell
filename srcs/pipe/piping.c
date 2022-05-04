/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:41 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/03 22:29:59 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mpipe.h"

void	piping(int nbcmd, t_cmd **cmd, t_dlist **envp, t_tlist *lst)
{
	t_pipes	pipes;

	pipes.here_doc = false; //! A changer plus tard pour quand on fera les here docs
	pipes.tlst = lst;
	pipes.nb_cmd = nbcmd;
	pipes.denv = envp;
	pipes.env = dlist_to_tab(*envp);
	pipes.nb_pipe = nbcmd - 1;
	(void)envp;
	open_io(*cmd, &pipes);
	ft_pipe(*cmd, &pipes);
	ft_free_tab(pipes.env);
}