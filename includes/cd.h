/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/13 16:22:59 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H

# define CD_H

# include "minishell.h"

void	*ft_cd(char *path_name, t_dlist **dupenv);
void	launch_cd(t_tlist *tlst, t_dlist **dupenv);

#endif