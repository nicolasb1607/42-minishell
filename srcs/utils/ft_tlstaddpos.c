#include "utils.h"

void	ft_tlstaddpos(t_tlist *tlst, char *str, int pos)
{
	int		i;
	t_tlist *new;
	t_tlist *curr;
	t_token *tok;
	t_tlist *tmp;

	i = 1;
	tok = init_token();
	curr = tlst;
	while (i < pos && curr->next)
	{
		printf("tslsaddpos i = %d\n", i);
		curr = curr->next;
		i++;
	}
	tok->content = str;
	new = ft_tlstnew(tok);
	tmp = curr->prev; 
	curr->prev = new;
	new->prev = tmp;
	new->next = curr;
	printf("aprs la boucle\n");
}
