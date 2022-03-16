/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:33:28 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/16 11:45:48 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H

# define UNSET_H

# include "minishell.h"

int		is_existing(char *varenv, t_dlist **dupenv);
void	ft_unset(char *varenv, t_dlist **dupenv);
void	loop_unset(t_tlist *tlst, t_dlist **dupenv);

#endif