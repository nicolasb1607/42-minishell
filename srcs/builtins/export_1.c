/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/04 22:00:13 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

char	*get_var(char *varenval)
{
	char	*varexport;
	int		i;

	varexport = NULL;
	i = 0;
	if (ft_containchar('=', varenval) == 0)
		return (NULL);
	while (varenval[i] && varenval[i] != '=')
		i++;
	varexport = ft_strncpy(varenval, i);
	return (varexport);
}

int	check_equal(char *str, t_tlist *tlst)
{
	int	i;

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

int	is_all_var_valid(t_tlist *tlst)
{
	t_tlist	*curr;
	char	*varenval;

	curr = tlst->next;
	while (curr)
	{
		varenval = get_var(curr->token->content);
		if (is_valid_varenv(varenval) == 1)
		{
			if (check_equal(curr->token->content, curr) == 1 && curr->next)
				curr = curr->next;
			else if (check_equal(curr->token->content, curr) == 2 && curr->next
				&& curr->next->next)
				curr = curr->next->next;
			else if (check_equal(curr->token->content, curr) == 0)
				curr = curr->next;
			else
				return (free(varenval), 1);
			free(varenval);
		}
		else
			return (free(varenval), 0);
	}
	return (1);
}

int	export_loop1(t_tlist *tlst, t_dlist *currenv, char *varexport)
{
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
	return (0);
}

int	export_loop2(t_tlist *tlst, t_dlist *currenv, char *varexport)
{
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
	return (0);
}
