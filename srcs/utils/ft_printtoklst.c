/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtoklst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/18 20:27:31 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_printtoklst(t_tlist *tlist)
{
	t_tlist	*curr;

	curr = tlist;
	while (curr)
	{
		if (curr->token->content)
		{
			ft_putstr(curr->token->type);
			ft_putchar('\t');
			if (ft_strlen(curr->token->type) < 8)
				ft_putchar('\t');
			ft_putstr(curr->token->content);
			ft_putchar('\t');
			if (curr->token->quote)
			{
				ft_putstr(curr->token->quote);
				ft_putchar('\t');
			}
			ft_putchar('\n');
		}
		if (!curr->token->content)
		{
			ft_putstr(curr->token->type);
			ft_putchar('\t');
			ft_putstr("NULL");
			ft_putchar('\t');
			if (curr->token->quote)
			{
				ft_putstr(curr->token->quote);
				ft_putchar('\t');
			}
			ft_putchar('\n');
		}
		curr = curr->next;
	}
}

void	ft_printalltok(t_tlist *tlist)
{
	t_tlist	*curr;
	
	curr = tlist;
	ft_putstr("\nTOKENS : ");
	while (curr)
	{
		ft_putstr("[");
		ft_putstr(curr->token->type);
		ft_putstr("]");
		if (curr->next)
			ft_putstr(" -> ");
		curr = curr->next;
	}
	ft_putstr("\n\n");
}

void print_t_cmd(t_cmd *cmd)
{
	static int	i = 0;
	
	dprintf(2, BBLU"");
	while (cmd)
	{
		dprintf(2, "\nNODE %d\n", i);
		i = i + 1;
		dprintf(2, "command %s\n", cmd->command);
		if (cmd->options)
			print_tab(cmd->options);
		if (cmd->bin)
			dprintf(2, "bin %s\n", cmd->bin);
		dprintf(2, "is_absolute %d\n", cmd->is_absolute);
		if (cmd->outfile)
		{
			dprintf(2, "outfile :\n");
			print_tab(cmd->outfile);
		}
		if (cmd->infile)
			dprintf(2, "infile %s\n", cmd->infile);
		// if (cmd->limiter)
		// 	dprintf(2, "limiter %s\n", cmd->limiter);
		// dprintf(2, "Double ? : %d\n", cmd->is_double);
		printf("Update i : %d\n", cmd->update_i);
		printf("Update o : %d\n", cmd->update_o);
		cmd = cmd->next;
	}
	dprintf(2, reset"\n");
}
