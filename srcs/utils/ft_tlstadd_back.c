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
		printf("Tentative d acces a tlstlast\n");
		last = ft_tlstlast(*alst);
		printf("Apres ftlstlast\n");
		last->next = new;
		new->prev = last;
	}
}
