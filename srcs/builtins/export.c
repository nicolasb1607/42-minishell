/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/14 15:34:47 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

/* TODO :

- Ne pas oublier de check si la variable que l on souhaite creer
	correspond aux standards
du nommage des variable d environnement a savoir
		- Seulement Des ALphanum et des UNDERSCORE
		- Ne doit pas commencer par un digit
		- Gerer plusieur variables et les variable dans les quotes

*/

char *get_var(t_tlist *tlst)
{
	char *varexport;
	int i;

	varexport = NULL;
	i = 0;
	if (ft_containchar('=', tlst->token->content) == 0)
		return (NULL);
	while (tlst->token->content[i] && tlst->token->content[i] != '=')
		i++;
	varexport = ft_strncpy(tlst->token->content, i);
	return (varexport);
}

int check_equal(char *str, t_tlist *tlst)
{
	int i;

	i = 0;
	while (str[i] != '=')
		i++;
	if (str[i + 1])
		return (1);
	else if (!tlst->next->token->space_after)
		return (2);
	else
		return (0);
}

void ft_export(t_tlist *tlst, t_dlist **dup_env)
{
	char *varexport;
	t_tlist *currtok;
	t_dlist *currenv;
	t_dlist	*new;

	currtok = tlst->next;
	currenv = *dup_env;
	varexport = get_var(currtok);
	if (is_valid_varenv(varexport) == 1)
	{
		if (check_equal(currtok->token->content, tlst) == 1 && is_existing(varexport, dup_env) == 1)
		{
			while (currenv)
			{
				if (ft_strncmp(currenv->content, varexport, ft_strlen(varexport)) == 0)
				{
					free(currenv->content);
					currenv->content = ft_strdup(currtok->token->content);
					return ;
				}
				currenv = currenv->next;
			}
		}
		if (check_equal(currtok->token->content, tlst) == 1 && is_existing(varexport, dup_env) == 0)
		{	
			printf("coco\n");
			new = ft_dlstnew(tlst->token->content);
			ft_dlstadd_back(dup_env, new);
		}
		// if (check_equal(currtok->token->content, tlst) == 2 && is_existing(varexport, dup_env) == 1)
		// {
			
		// }
		// if (check_equal(currtok->token->content, tlst) == 2 && is_existing(varexport, dup_env) == 0)
		// {
		// 	return ;
		// }
		// if (check_equal(currtok->token->content, tlst) == 0)
	}
}

	// void	ft_export(char *varnvalue, t_dlist **dupenv)
	// {
	// 	char	*varexport;
	// 	t_dlist	*curr;
	// 	t_dlist	*new;

	// 	varexport = get_var(varnvalue);
	// 	if (!varexport)
	// 		return ;
	// 	if (is_existing(varexport, dupenv) == 1)
	// 	{
	// 		curr = *dupenv;
	// 		while (curr)
	// 		{
	// 			if (ft_strncmp(curr->content, varexport, ft_strlen(varexport)) == 0)
	// 			{
	// 				free(curr->content);
	// 				curr->content = ft_strdup(varnvalue);
	// 				return ;
	// 			}
	// 			curr = curr->next;
	// 		}
	// 	}
	// 	new = ft_dlstnew(ft_strdup(varnvalue));
	// 	ft_dlstadd_back(dupenv, new);
	// }
