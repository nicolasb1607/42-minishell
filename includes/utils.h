#ifndef UTILS_H
# define UTILS_H

#include "minishell.h"

t_token	*ft_tlstnew(char *content);
t_token	*tab_to_list(char **tab, t_token *head);
void	ft_tlstadd_back(t_token **alst, t_token *new);
t_token	*ft_tlstlast(t_token *lst);

#endif