#include "utils.h"

t_token	*ft_tlstlast(t_token *lst)
{
	t_token	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
