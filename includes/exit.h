/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:34:20 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/15 14:51:59 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H

# define EXIT_H

# include "minishell.h"
# include "errno.h"

void	ft_exit(void);
void	disp_synt_erro(char *str);
void	disp_mem_error(void);

#endif