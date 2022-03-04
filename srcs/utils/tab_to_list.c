#include "utils.h"

// t_tlist	*tab_to_list(char **tab, t_tlist *head)
// {
// 	int	i;
// 	t_tlist *new;
	
// 	i = 0;
// 	while (tab[i])
// 	{
// 		new = ft_tlstnew(ft_strdup(tab[i]));
// 		ft_tlstadd_back(&head, new);
// 		i++;
// 	}
// 	return (head);
// }

char	**list_to_tab(t_tlist *alst)
{
	char	**tmp;
	int		size;
	int		i;
	t_tlist	*curr;

	i = -1;
	curr = alst;
	size = ft_tlstsize(curr);
	tmp = malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		tmp[i] = ft_strdup(curr->token->content);
		curr = curr->next;
	}
	tmp[i] = ft_strdup("");
	return (tmp);
}
