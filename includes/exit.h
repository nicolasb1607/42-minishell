/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:34:20 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/03 22:25:10 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H

# define EXIT_H

# include "minishell.h"
# include "errno.h"

void	ft_exit(t_tlist *tlst, t_cmd **cmd);
void	disp_synt_erro(char *str);
void	disp_mem_error(void);

#endif