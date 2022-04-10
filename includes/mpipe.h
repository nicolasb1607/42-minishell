/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpipe.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:53:59 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/10 12:56:28 by ngobert          ###   ########.fr       */
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
	int		fd_in;
	int		fd_out;
	pid_t	child[255];
	char	**env;
	bool	here_doc;
}			t_pipes;

/* PROTOTYPES */
int		open_i(t_cmd *cmd, t_pipes *pipes);
int		open_o(t_cmd *cmd, t_pipes *pipes);
int		open_io(t_cmd *cmd, t_pipes *pipes);
void	piping(int nbcmd, t_cmd *cmd, char **envp);
void	first_cmd(t_cmd *cmd, t_pipes *pipes);
void	mid_cmd(t_cmd *cmd, t_pipes *pipes, int i);
void	last_cmd(t_cmd *cmd, t_pipes *pipes);


#endif