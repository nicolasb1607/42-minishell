/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:13 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/09 14:55:50 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

/* INCLUDES */
# include "minishell.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "libft.h"

/* STRUCTURE */
typedef struct s_data
{
	int		argc;
	int		nb_cmd;
	int		nb_pipe;
	int		**pipe;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	pid_t	child[255];
	bool	here_doc;
}			t_data;

/* PROTOTYPES */
t_data	get_args(int argc, char **argv, char **envp);
void	ft_error(const char *str);
void	pipe_creator(t_data *data);
char	*get_bin(char *cmd, char **paths);
char	*get_line(t_data *data);
char	**get_paths(t_data *data);
void	run_first(t_data *data);
void	run_mid(t_data *data, int i);
void	run_last(t_data *data);
char	*get_bin_custom(char *cmd, char **paths, t_tlist *tlst);
void	pipes(int argc, char **argv, char **envp);

#endif