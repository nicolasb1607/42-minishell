/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:42:51 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/12 14:10:39 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
char	*ft_strchr_printf(const char *s, int c);
void	ft_putchar_printf(char c, int *printed);
void	ft_putstr_printf(char *str, int *printed);
void	ft_putnbr_printf(int nbr, int *printed);
void	ft_putnbru_printf(unsigned int nbr, int *printed);
void	ft_putnbr_hexa_printf(unsigned int nbr, int *printed);
void	ft_putnbr_hexa_maj_printf(unsigned int nbr, int *printed);
void	ft_pointer_printf(unsigned long int pointer, int *printed, int *init);
size_t	ft_strlen_printf(const char *s);

#endif