/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/17 10:20:07 by nburat-d         ###   ########.fr       */
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
void	handle_quit(int signum);

#endif