#include"utils.h"

void	ft_printtoklst(t_tlist *tlist)
{
	t_tlist *curr;

	curr = tlist;
	while (curr)
	{
		ft_putstr(curr->token->type);
		ft_putchar('\n');
		curr = curr->next;	
	}
}