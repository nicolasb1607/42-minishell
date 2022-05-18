/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/18 12:51:56 by nburat-d         ###   ########.fr       */
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
	char *get_var_ret;

	while (currenv)
	{
		get_var_ret = NULL;
		get_var_ret = get_var(currenv->content);		
		if (ft_strncmp(currenv->content, varexport,
				ft_strlen(get_var_ret)) == 0)
		{
			free(currenv->content);
			free(get_var_ret);
			currenv->content = ft_strdup(tlst->token->content);
			return (1);
		}
		currenv = currenv->next;
	}
	return (0);
}

int	export_loop2(t_tlist *tlst, t_dlist *currenv, char *varexport)
{
	char	*var;

	while (currenv)
	{
		var = get_var(currenv->content);
		if (ft_strncmp(currenv->content, varexport,
				ft_strlen(var)) == 0)
		{
			free(currenv->content);
			currenv->content = ft_strjoin(tlst->token->content,
					tlst->next->token->content);
			return (free(var), 2);
			var = (free(var), NULL);
		}
		if (var)
			var = (free(var), NULL);
		currenv = currenv->next;
	}
	if (var)
		free(var);
	return (0);
}
