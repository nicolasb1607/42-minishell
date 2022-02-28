#include "utils.h"

t_token	*tab_to_list(char **tab, t_token *head)
{
	int	i;
	t_token *new;
	
	i = 0;
	while (tab[i])
	{
		new = ft_tlstnew(ft_strdup(tab[i]));
		ft_tlstadd_back(&head, new);
		i++;
	}
	return (head);
}