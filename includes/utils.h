/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/24 14:10:28 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

t_tlist	*ft_tlstnew(t_token *token);
t_tlist	*tab_to_list(char **tab, t_tlist *head);
char	**tlist_to_tab(t_tlist *alst);
void	ft_tlstadd_back(t_tlist **alst, t_tlist *new);
t_tlist	*ft_tlstlast(t_tlist *lst);
int		ft_tlstsize(t_tlist *lst);
void	ft_printtoklst(t_tlist *tlist);
void	ft_tlstiter(
			t_tlist *lst, t_minishell *mshell,
			void (*f)(t_token *, t_minishell *));
char	**dlist_to_tab(t_dlist *alst);

#endif