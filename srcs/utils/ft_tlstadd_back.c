#include "utils.h"

void	ft_tlstadd_back(t_token **alst, t_token *new)
{
	t_token	*last;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (*alst != NULL && new != NULL)
	{
		last = ft_tlstlast(*alst);
		last->next = new;
	}
}
