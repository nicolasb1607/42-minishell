/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtoklst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:42 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/14 16:01:43 by nburat-d         ###   ########.fr       */
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
			fprintf(stderr,"||");
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
	
	printf(BBLU"");
	while (cmd)
	{
		printf("\nNODE %d\n", i);
		i = i + 1;
		printf("command %s\n", cmd->command);
		if (cmd->options)
			print_tab(cmd->options);
		printf("bin %s\n", cmd->bin);
		printf("is_absolute %d\n", cmd->is_absolute);
		if (cmd->outfile)
		{
			printf("outfile :\n");
			print_tab(cmd->outfile);
		}
		if (cmd->infile)
			printf("infile %s\n", cmd->infile);
		if (cmd->limiter)
			printf("limiter %s\n", cmd->limiter);
		printf("Double ? : %d\n", cmd->is_double);
		cmd = cmd->next;
	}
	printf(reset"\n");
}
