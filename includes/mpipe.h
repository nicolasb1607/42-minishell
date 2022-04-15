/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpipe.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:53:59 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/15 11:19:48 by ngobert          ###   ########.fr       */
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
	t_tlist	*tlst;
	t_dlist	**denv;
}			t_pipes;

/* PROTOTYPES */
int		open_i(t_cmd *cmd, t_pipes *pipes);
int		open_o(t_cmd *cmd, t_pipes *pipes);
int		open_io(t_cmd *cmd, t_pipes *pipes);
void	piping(int nbcmd, t_cmd *cmd, t_dlist **envp, t_tlist *lst);
void	first_cmd(t_cmd *cmd, t_pipes *pipes);
void	mid_cmd(t_cmd *cmd, t_pipes *pipes, int i);
void	last_cmd(t_cmd *cmd, t_pipes *pipes);
int		is_builtin(t_tlist *lst);
int	is_builtincmd(t_cmd *cmd);
void	exec_builtin(t_tlist *builtin, t_dlist **denv);
void	ft_pipe(t_cmd *cmd, t_pipes *data);
char	*ft_strndup(char *str, int i);

#endif