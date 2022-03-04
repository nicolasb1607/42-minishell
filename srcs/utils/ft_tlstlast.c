#include "utils.h"

t_tlist	*ft_tlstlast(t_tlist *lst)
{
	t_tlist	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
