/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:23:00 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 18:24:25 by nburat-d         ###   ########.fr       */
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
// char	*ft_prompt(void)
// {
// 	char	*ret_line;

// 	ret_line = readline("Minsdfsdfsdfishell > ");

// 	printf("Return : %s\n", ret_line);
// 	return (ret_line);
// }