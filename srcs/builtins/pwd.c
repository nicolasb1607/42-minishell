/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:37:32 by nburat-d          #+#    #+#             */
/*   Updated: 2022/03/09 17:37:33 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

void	ft_pwd(void)
{
	char	*line;

	line = NULL;
	line = getcwd(line, 2048);
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
	return ;
}
