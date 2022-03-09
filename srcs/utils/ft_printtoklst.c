#include"utils.h"

void	ft_printtoklst(t_tlist *tlist)
{
	t_tlist *curr;

	curr = tlist;
	while (curr)
	{
		if (curr->token->content)
		{
			ft_putstr(curr->token->content);
			ft_putchar('\n');
		}
		curr = curr->next;
	}
}

