/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 17:31:48 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIG_H

# define HANDLE_SIG_H

# include "minishell.h"
# include <signal.h>

void	free_tab(t_data *data);
// void	handle_sig(int signum, siginfo_t *si_signo , t_data *data);
// // // void	handle_ctrld(void);
// // // void	handle_ctrlbslash(void);

#endif