/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:45:44 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/07 15:53:49 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_FT_H
# define INIT_FT_H

# include "minishell.h"

void	init_ft(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead);
void	only1cmd(t_tlist *tlst, t_dlist **dupenv, t_cmd *chead);
void	free_tcmd(t_cmd **cmd);


#endif