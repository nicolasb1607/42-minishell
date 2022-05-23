/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpipe.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:53:59 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/23 14:33:50 by nburat-d         ###   ########.fr       */
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
void	piping(int nbcmd, t_cmd **cmd, t_dlist **envp, t_tlist *lst);
void	first_cmd(t_cmd *cmd, t_pipes *pipes);
void	mid_cmd(t_cmd *cmd, t_pipes *pipes, int i);
void	last_cmd(t_cmd *cmd, t_pipes *pipes);
int		is_builtin(t_tlist *lst);
int		is_builtincmd(t_cmd *cmd);
void	exec_builtin(t_tlist *builtin, t_dlist **denv, t_cmd **cmd);
void	ft_pipe(t_cmd *cmd, t_pipes *data);
char	*ft_strndup(char *str, int i);
int		is_forkbuiltin(t_cmd *cmd);
int		tab_size(char **tab);
void	sig_norm(t_pipes *pipes, t_cmd **chead);
void	close_child(int *pfd, int fd_in);
void	ft_norm(int *status);
void	close_pfd(int *pfd, int fd_in, t_cmd *cmd);
int		open_o_norm(t_cmd **cmd, t_pipes **pipes, char *file_name, int fd);
int		open_o_norm2(t_pipes **pipes);
char	*norm_open(t_cmd **cmd, int i);
int		check_all_al(char **tab);
void	exec_builtin_exit(t_tlist **builtin, t_cmd **cmd);

#endif