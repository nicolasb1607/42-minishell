/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:26:48 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/31 14:46:32 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H

# define EXPORT_H

# include "minishell.h"

char	*get_var(char *varenval);
int		check_equal(char *str, t_tlist *tlst);
int		is_all_var_valid(t_tlist *tlst);
int		export_loop1(t_tlist *tlst, t_dlist *currenv, char *varexport);
int		export_loop2(t_tlist *tlst, t_dlist *currenv, char *varexport);
int		spread_on_one_tok(t_tlist *tlst, t_dlist *currenv,
			char *varexport, t_dlist **dup_env);
int		spread_on_two_tok(t_tlist *tlst, t_dlist *currenv,
			char *varexport, t_dlist **dup_env);
int		ft_export(t_tlist *tlst, t_dlist **dup_env);
void	loop_export(t_tlist *tlst, t_dlist **dup_env);
void	ft_sort_tab(char **tab);
void	print_declared_var(t_dlist **dup_env);

#endif