#include "utils.h"

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
