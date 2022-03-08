#include "utils.h"

void	ft_tlstiter(t_tlist *lst, t_minishell *mshell, void (*f)(t_token *, t_minishell *))
{
	t_tlist	*current;

	while (lst != NULL)
	{
		//printf("Dans lstiter\n");
		current = lst;
		lst = lst->next;
		f(current->token, mshell);
	}
}
