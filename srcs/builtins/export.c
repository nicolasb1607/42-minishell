/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/15 17:09:53 by nburat-d         ###   ########.fr       */
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
	else if (!tlst->token->space_after)
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

int ft_export(t_tlist *tlst, t_dlist **dup_env)
{
	char *varexport;
	t_dlist *currenv;
	t_dlist *new;

	currenv = *dup_env;
	if (!tlst)
		return (0);	
	varexport = get_var(tlst->token->content);
	printf("varexport = %s\n", varexport);
	if (is_valid_varenv(varexport) == 1 && ft_containchar('=', tlst->token->content))
	{
		printf("is a valid var\n");
		if (check_equal(tlst->token->content, tlst) == 1 && is_existing(varexport, dup_env) == 1)
		{
			printf("Premiere condition \n");
			while (currenv)
			{
				if (ft_strncmp(currenv->content, varexport,
							   ft_strlen(get_var(currenv->content))) == 0)
				{
					free(currenv->content);
					currenv->content = ft_strdup(tlst->token->content);
					return (1);
				}
				currenv = currenv->next;
			}
		}
		else if (check_equal(tlst->token->content, tlst) == 1 && is_existing(varexport, dup_env) == 0)
		{
			printf("Deuxieme condition \n");
			new = ft_dlstnew(ft_strdup(tlst->token->content));
			ft_dlstadd_back(dup_env, new);
			return (1);
		}
		else if (check_equal(tlst->token->content, tlst) == 2 && is_existing(varexport, dup_env) == 1)
		{
			printf("Troisieme condition \n");
			while (currenv)
			{
				if (ft_strncmp(currenv->content, varexport,
							   ft_strlen(get_var(currenv->content))) == 0)
				{
					free(currenv->content);
					currenv->content = ft_strjoin(tlst->token->content,
												  tlst->next->token->content);
					return (2);
				}
				currenv = currenv->next;
			}
		}
		else if (check_equal(tlst->token->content, tlst) == 2 && is_existing(varexport, dup_env) == 0)
		{
			printf("Quatrieme condition \n");
			new = ft_dlstnew(ft_strjoin(tlst->token->content,
										tlst->next->token->content));
			ft_dlstadd_back(dup_env, new);
			return (2);
		}
		else if (check_equal(tlst->token->content, tlst) == 0)
		{
			printf("Derniere condition \n");
			new = ft_dlstnew(ft_strdup(tlst->token->content));
			ft_dlstadd_back(dup_env, new);
			return (1);
		}
	}
	return (0);
}

void loop_export(t_tlist *tlst, t_dlist **dup_env)
{
	t_tlist *currtok;
	int i;

	currtok = tlst->next;
	i = ft_export(currtok, dup_env);
	printf("return export = %d\n", i);
	while (currtok)
	{
		if (i == 1 && currtok->next)
		{
			currtok = currtok->next;
			ft_export(currtok, dup_env);
		}
		else if (i == 2 && currtok->next && currtok->next->next)
		{
			currtok = currtok->next->next;
			printf("ret export dans loop = %d\n", ft_export(currtok, dup_env));
		}
		else
			break ;
	}
}