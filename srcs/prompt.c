/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:23:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/18 13:48:53 by ngobert          ###   ########.fr       */
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

char	*ft_strsub(char *str, int to_sub, int len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		sub[i] = str[to_sub + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_prompt(t_minishell *g_mshell)
{
	char	*ret_line;
	char	*prompt;
	char	*secprompt;

	prompt = ft_strnstr(getcwd(NULL, 2048), "homes/", ft_strlen(getcwd(NULL, 2048)));
	secprompt = ft_strnstr(getcwd(NULL, 2048), "home/", ft_strlen(getcwd(NULL, 2048)));
	if (prompt)
		prompt = ft_strsub(prompt, 6, ft_strlen(prompt) - 6);
	else if (secprompt)
		prompt = ft_strsub(secprompt, 5, ft_strlen(secprompt) - 5);
	else
		prompt = getcwd(NULL, 2048);
	prompt = ft_strjoin(prompt, " $> ");
	ret_line = readline(prompt);
	if(ret_line == NULL)
	{
		printf(GRN"exit\n"CRESET);
		free_dlist(g_mshell->env);
		clear_history();
		exit (0);
	}
	add_history(ret_line);
	return (ret_line);
}
