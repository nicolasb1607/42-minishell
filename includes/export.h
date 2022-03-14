/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:56 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/14 13:59:33 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H

# define EXPORT_H

# include "minishell.h"

char	*get_var(t_tlist *tlst);
void	ft_export(t_tlist *tlst, t_dlist **dup_env);


#endif