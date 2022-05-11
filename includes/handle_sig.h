/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/11 10:55:56 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIG_H

# define HANDLE_SIG_H

# include "minishell.h"
# include <signal.h>

void	free_dlist(t_dlist **dlist);
void	handler_main(int signum);
void	handler_cmd(int signum);
void	handler_heredoc(int signum);

#endif