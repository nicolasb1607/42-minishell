#include "lexer.h"

int	ft_tlstsize(t_tlist *lst)
{
	t_tlist	*current;
	int		size;

	current = lst;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
