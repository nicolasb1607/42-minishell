/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:46:25 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/13 14:35:50 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	__is_type(t_tlist *lst, char *type)
{
	if (ft_strncmp(lst->token->type, type, ft_strlen(type)) == 0)
		return (1);
	return (0);
}

int	check_pipe(t_tlist *lst)
{
	if (!lst->prev || !lst->next)
		return (disp_synt_erro("|"), 0);
	else if (ft_strcmp(lst->next->token->type, T_L_DIR) == 0)
		return (1);
	return (1);
}

int	check_rdir(t_tlist *lst)
{
	if (!lst->next)
		return (disp_synt_erro("newline"), 0);
	else if (!__is_type(lst->next, T_STRING))
		return (disp_synt_erro("newline"), 0);
	return (1);
}

int	check_empty_list_expand(t_tlist *lst)
{
	if (!lst->token->content || lst->token->content[0] == '\0')
		return(0);
	else
		return(1);
	
}
int	parser(t_tlist *lst)
{
	// if (check_empty_list_expand(lst) == 0)
	// 	return (0);
	while (lst)
	{
		if (__is_type(lst, T_PIPE))
		{
			if (!check_pipe(lst))
			{	
				g_mshell.err_exit = 2;
				return (0);
			}
		}
		else if (!__is_type(lst, T_STRING))
		{
			if (!check_rdir(lst))
			{	
				g_mshell.err_exit = 2;
				return (0);
			}
		}
		lst = lst->next;
	}
	return (1);
}
