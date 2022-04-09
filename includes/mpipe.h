/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpipe.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:53:59 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/09 15:05:27 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MPIPE_H
# define MPIPE_H

/* INCLUDES */
# include "minishell.h"

/* STRUCTURE */
typedef struct s_pipes
{
	int		nb_cmd;
	int		nb_pipe;
	int		**pipe;
	pid_t	child[255];
	char	**env;
}			t_pipes;

/* PROTOTYPES */
int		open_i(t_cmd *cmd);
int		open_o(t_cmd *cmd);
int		open_io(t_cmd *cmd);
void	piping(int nbcmd, t_cmd *cmd, char **envp);

#endif