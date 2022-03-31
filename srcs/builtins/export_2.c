/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:27:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/31 14:47:33 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	spread_on_one_tok(t_tlist *tlst, t_dlist *currenv,
	char *varexport, t_dlist **dup_env)
{
	t_dlist	*new;

	if (check_equal(tlst->token->content, tlst) == 1
		&& is_existing(varexport, dup_env) == 1)
	{
		if (export_loop1(tlst, currenv, varexport) == 1)
			return (1);
	}
	else if (check_equal(tlst->token->content, tlst) == 1
		&& is_existing(varexport, dup_env) == 0)
	{
		new = ft_dlstnew(ft_strdup(tlst->token->content));
		ft_dlstadd_back(dup_env, new);
		return (1);
	}
	return (0);
}

int	spread_on_two_tok(t_tlist *tlst, t_dlist *currenv,
	char *varexport, t_dlist **dup_env)
{
	t_dlist	*new;

	if (check_equal(tlst->token->content, tlst) == 2
		&& is_existing(varexport, dup_env) == 1)
	{
		if (export_loop2(tlst, currenv, varexport) == 2)
			return (2);
	}
	else if (check_equal(tlst->token->content, tlst) == 2
		&& is_existing(varexport, dup_env) == 0)
	{
		new = ft_dlstnew(ft_strjoin(tlst->token->content,
					tlst->next->token->content));
		ft_dlstadd_back(dup_env, new);
		return (2);
	}
	return (0);
}

int	no_assigment(t_tlist *tlst, t_dlist *currenv,
	char *varexport, t_dlist **dup_env)
{
	t_dlist	*new;

	if (check_equal(tlst->token->content, tlst) == 0
		&& is_existing(varexport, dup_env) == 1)
	{
		while (ft_strcmp(varexport, get_var(currenv->content)) != 0)
			currenv = currenv->next;
		free(currenv->content);
		currenv->content = ft_strdup(tlst->token->content);
		return (1);
	}
	else if (check_equal(tlst->token->content, tlst) == 0
		&& is_existing(varexport, dup_env) == 0)
	{
		new = ft_dlstnew(ft_strdup(tlst->token->content));
		ft_dlstadd_back(dup_env, new);
		return (1);
	}
	return (0);
}

int	ft_export(t_tlist *tlst, t_dlist **dup_env)
{
	char	*varexport;
	t_dlist	*currenv;

	currenv = *dup_env;
	if (!tlst)
		return (0);
	varexport = get_var(tlst->token->content);
	if (is_valid_varenv(varexport) == 1
		&& ft_containchar('=', tlst->token->content))
	{
		if (spread_on_one_tok(tlst, currenv, varexport, dup_env) == 1)
			return (1);
		else if (spread_on_two_tok(tlst, currenv, varexport, dup_env) == 2)
			return (2);
		else if (no_assigment(tlst, currenv, varexport, dup_env) == 1)
			return (1);
	}
	return (0);
}

void	loop_export(t_tlist *tlst, t_dlist **dup_env)
{
	t_tlist	*currtok;
	int		i;

	if (tlst->next)
	{
		if (!is_all_var_valid(tlst))
			return ;
		currtok = tlst->next;
		i = ft_export(currtok, dup_env);
		while (currtok)
		{
			if (i == 1 && currtok->next)
			{
				currtok = currtok->next;
				ft_export(currtok, dup_env);
			}
			else if (i == 2 && currtok->next && currtok->next->next)
				currtok = currtok->next->next;
			else
				break ;
		}
	}
	else
		print_declared_var(dup_env);
}
