/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:20:55 by ngobert           #+#    #+#             */
/*   Updated: 2022/04/01 14:26:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H

# define EXEC_H

# include "minishell.h"

void	ft_clstadd_back(t_cmd **alst, t_cmd *new);
t_cmd	*ft_clstlast(t_cmd *lst);
t_cmd	*ft_clstnew(void);
t_cmd	*tlst_to_cmd(t_tlist *tlst);
char	**get_path_to_cmd(t_tlist *tlst, t_dlist **dupenv);
int		is_operator(char *content);
void	update_bin(char **path, t_cmd *cmd, t_tlist *tlst);
void	init_cmd(t_cmd *cmd);

#endif