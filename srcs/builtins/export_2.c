/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:21:04 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/16 11:21:55 by nburat-d         ###   ########.fr       */
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

int	ft_export(t_tlist *tlst, t_dlist **dup_env)
{
	char	*varexport;
	t_dlist	*currenv;
	t_dlist	*new;

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
		else if (check_equal(tlst->token->content, tlst) == 0)
		{
			new = ft_dlstnew(ft_strdup(tlst->token->content));
			ft_dlstadd_back(dup_env, new);
			return (1);
		}
	}
	return (0);
}

void	loop_export(t_tlist *tlst, t_dlist **dup_env)
{
	t_tlist	*currtok;
	int		i;

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
		{
			currtok = currtok->next->next;
		}
		else
			break ;
	}
}
