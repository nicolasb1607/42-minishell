/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:55 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/12 13:37:21 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H

# define EXEC_H

# include "minishell.h"

void	ft_clstadd_back(t_cmd **alst, t_cmd *new);
t_cmd	*ft_clstlast(t_cmd *lst);
t_cmd	*ft_clstnew(void);
t_cmd	*tlst_to_cmd(t_tlist **tlst, t_dlist **dupenv);
char	**get_path_to_cmd(t_dlist **dupenv);
int		is_operator(char *content);
int		update_bin(char **path, t_cmd *cmd, t_tlist *tlst);
void	init_cmd(t_cmd *cmd);
int		count_command(t_tlist *tlst);
char	**tab_dup(char **tab);
t_cmd	*cpy_tcmd(t_cmd **cmd);
int		is_redir(char *content);
void	make_heredoc(t_cmd *cmd, t_dlist **dupenv);
char	*create_tmp(void);
int		is_absolute(char *cmd);
void	update_io(t_cmd *cmd, t_tlist *lst, int ret, t_dlist **dupenv);
void	exit_status_here_doc(int pid);

#endif