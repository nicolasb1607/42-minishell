/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:23:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/14 13:23:45 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

/*
TO DO : 

- Create a loop which wait for a command to be entered

- Once something is writen, the function should
	* Read the line (read_line)
	* Parse into PROGRAM and ARGUMENTS (lexer)
	* Execute the parsed command (execve)

- Once the excution is done, it starts again and put a prompt
*/
char	*ft_prompt(t_minishell *g_mshell)
{
	char	*ret_line;

	ret_line = readline(BGRN"➜"BCYN"  le_nathou_shell "BYEL"✗ "reset);
	if(ret_line == NULL)
	{
		printf(GRN"\nexit\n"CRESET);
		free_dlist(g_mshell->env);
		clear_history();

		
		exit (0);
	}
		
	add_history(ret_line);
	return (ret_line);
}
