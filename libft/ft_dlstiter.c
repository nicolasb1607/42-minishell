#include "libft.h"

void	ft_dlstiter(t_dlist *lst, void(*f)(void *))
{
	t_dlist *current;

	while (lst != NULL)
	{
		current = lst;
		lst = lst->next;
		f(current->content);
	}
}
