/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:34:20 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/22 10:12:24 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H

# define EXIT_H

# include "minishell.h"
# include "errno.h"

void	ft_exit(t_tlist *tlst);
void	disp_synt_erro(char *str);
void	disp_mem_error(void);

#endif