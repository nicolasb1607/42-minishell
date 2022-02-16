/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:32:49 by nburat-d          #+#    #+#             */
/*   Updated: 2021/12/01 08:49:35 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Supprime et libère la mémoire de l’élément passé en
paramètre, et de tous les élements qui suivent, à
l’aide de del et de free(3)
Enfin, le pointeur initial doit être mis à NULL.

#1. L’adresse du pointeur vers un élément.
#2. L’adresse de la fonction permettant de
supprimer le contenu d’un élément.*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	current = NULL;
	while (*lst != NULL)
	{
		current = *lst;
		*lst = (*lst)->next;
		del(current->content);
		free(current);
	}
}
