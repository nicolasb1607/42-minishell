/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:45:44 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/05 15:37:35 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_FT_H
# define INIT_FT_H

# include "minishell.h"

void init_ft(t_tlist *tlst, t_dlist **dupenv, t_cmd *cmd, t_cmd **chead);

#endif