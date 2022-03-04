#include "utils.h"

void	ft_tlstadd_back(t_tlist **alst, t_tlist *new)
{
	t_tlist	*last;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (*alst != NULL && new != NULL)
	{
		last = ft_tlstlast(*alst);
		last->next = new;
		new->prev = last;
	}
}
