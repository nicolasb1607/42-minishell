/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:31:41 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/11 14:58:52 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H

# include "minishell.h"
# include <errno.h>

int		look_for_next_quote(char *str, char q, int *i);
int		check_quote(char *str);
void	init_lexer(t_lexer *lexer, char *str);
t_token	*init_token(void);
void	advance(t_lexer *lexer);
void	assign_toks(t_token *token, char *content, char *type);
void	make_quote_string(t_token *token, t_lexer *lexer);
void	make_string(t_token *token, t_lexer *lexer);
t_token	*make_token(t_lexer *lexer);
int		ft_isenv(char c);
int		is_valid_varenv(char *str);
char	*look_for_varenv_value(char *varenv, t_dlist **env);
char	*expand(t_token *token, int i, t_minishell *mshell);
void	expandtok(t_token *token, t_minishell *mshell);
t_tlist	*init_tlist(char *str, t_tlist *tlist, t_minishell *mshell);
//void	ft_error(char *str);
int		parser(t_tlist *lst);
int	__is_type(t_tlist *lst, char *type);

#endif