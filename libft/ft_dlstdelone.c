#include "libft.h"

void	ft_dlstdelone(t_dlist *lst, void(*del)(void*))
{
	t_dlist	*tmp;

	tmp = lst;
	if (lst != NULL && del != NULL)
	{
		lst->next->prev = tmp->prev;
		lst->prev->next = tmp->next;
		(*del)(lst->content);
		free(lst);
	}
}
