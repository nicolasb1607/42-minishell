/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:32:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/19 10:55:52 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"
# include "mpipe.h"

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
void	print_tab(char **tab);
void	ft_printalltok(t_tlist *tlist);
void	ft_tlstdelone(t_tlist *lst, void (*del)(void*), t_tlist **tlist);
char	**ft_split_custom(char *s, char c);
void	classicsplit(char *s, char **split, int *i, int *j);
char	**ft_split_custom(char *s, char c);
int		ft_wordcount_custom(char *s, char c);
int		lenquote_cu(char *str, int i, char q);
int		ft_wordlen_cu(char *s, char c);
char	**ft_cut_cu(char *s, char **split, char c, int i);
char	**free_tab_cu(char **tab);
char	**ft_free_tab(char **tab);
void	print_t_cmd(t_cmd *cmd);
void	unlink_hd(void);
void	close_fd(void);

/*	INIT_FT_UTILS	*/
int		is_builtincmd(t_cmd *cmd);
int		is_forkbuiltin(t_cmd *cmd);
void	cpy_till_pipe(t_tlist **tlist, t_tlist **tlistnew);
int		is_builtin(t_tlist *lst);

/*	INIT_FT_FREE	*/
char	**ft_free_tab(char **tab);
void	free_tcmd(t_cmd **cmd);

/*	INIT_FT_MKCMD	*/
t_cmd	*make_commands(t_tlist *tlst, t_cmd **chead,
			t_dlist **dupenv, t_tlist *curr);
t_cmd	*mk_built(t_tlist **tlst, t_dlist **dupenv);
t_cmd	*mk_cmd_b(t_tlist **tlst, t_dlist **dupenv,
			t_cmd *chead, t_tlist **curr);

#endif
