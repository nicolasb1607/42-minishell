/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:06 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/19 15:49:06 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H

# define ENV_H

# include "minishell.h"

t_dlist	*ft_dupenv(t_dlist *lst, char **envp);
t_dlist	*ft_dupenv_def(t_dlist *lst, char *envp);
void	ft_env(t_dlist **dupenv);

#endif