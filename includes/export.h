/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:56 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 17:31:58 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H

# define EXPORT_H

# include "minishell.h"

char	*get_var(char *varnvalue);
void	ft_export(char *varnvalue, t_dlist **dupenv);

#endif