/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/15 15:52:10 by nburat-d         ###   ########.fr       */
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

char *get_var(char *varenval)
{
	char *varexport;
	int i;

	varexport = NULL;
	i = 0;
	if (ft_containchar('=', varenval) == 0)
		return (NULL);
	while (varenval[i] && varenval[i] != '=')
		i++;
	varexport = ft_strncpy(varenval, i);
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

/*
On doit checker si tous les arguments sont valid avant meme de rajouter 
la premier variable a l environnement

*/
// int is_all_var_valid(t_tlist *tlst)
// {
// 	int is_valid;
// }

void ft_export(t_tlist *tlst, t_dlist **dup_env)
{
	char *varexport;
	t_tlist *currtok;
	t_dlist *currenv;
	t_dlist *new;

	currtok = tlst->next;
	currenv = *dup_env;

	
	varexport = get_var(currtok->token->content);
		//printf("varexport = %s\n", varexport);
		if (is_valid_varenv(varexport) == 1 && ft_containchar('=', currtok->token->content))
		{
			printf("is a valid var\n");
			if (check_equal(currtok->token->content, tlst) == 1 && is_existing(varexport, dup_env) == 1)
			{
				while (currenv)
				{
					if (ft_strncmp(currenv->content, varexport,
								   ft_strlen(get_var(currenv->content))) == 0)
					{
						free(currenv->content);
						currenv->content = ft_strdup(currtok->token->content);
						return ;
					}
					currenv = currenv->next;
				}
			}
			else if (check_equal(currtok->token->content, tlst) == 1 && is_existing(varexport, dup_env) == 0)
			{
				new = ft_dlstnew(ft_strdup(currtok->token->content));
				ft_dlstadd_back(dup_env, new);
			}
			if (check_equal(currtok->token->content, tlst) == 2 && is_existing(varexport, dup_env) == 1)
			{
				while (currenv)
				{
					if (ft_strncmp(currenv->content, varexport,
								   ft_strlen(get_var(currenv->content))) == 0)
					{
						free(currenv->content);
						currenv->content = ft_strjoin(currtok->token->content,
													  currtok->next->token->content);
						return ;
					}
					currenv = currenv->next;
				}
			}
			else if (check_equal(currtok->token->content, tlst) == 2 && is_existing(varexport, dup_env) == 0)
			{
				new = ft_dlstnew(ft_strjoin(currtok->token->content,
											currtok->next->token->content));
				ft_dlstadd_back(dup_env, new);
				return ;
			}
			if (check_equal(currtok->token->content, tlst) == 0)
			{
				new = ft_dlstnew(ft_strdup(currtok->token->content));
				ft_dlstadd_back(dup_env, new);
				return ;
			}
		}
	}
