/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:42:15 by nburat-d          #+#    #+#             */
/*   Updated: 2022/04/10 19:21:35 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Écrit le caractère ’c’ sur le file descriptor
donné

#1. Le caractère à écrire.
#2. Le file descriptor sur lequel écrire. */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
