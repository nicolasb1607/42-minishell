/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:29:18 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/12 14:11:29 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putnbr_printf(int nbr, int *printed)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*printed = *printed + 11;
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
		*printed = *printed + 1;
	}
	if (nbr > 9)
	{
		ft_putnbr_printf(nbr / 10, printed);
		nbr = nbr % 10;
	}
	if (nbr <= 9)
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
		*printed = *printed + 1;
		return ;
	}
}

void	ft_putnbru_printf(unsigned int nbr, int *printed)
{
	if (nbr > 9)
	{
		ft_putnbr_printf(nbr / 10, printed);
		nbr = nbr % 10;
	}
	if (nbr <= 9)
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
		*printed = *printed + 1;
	}
	return ;
}

void	ft_putnbr_hexa_printf(unsigned int nbr, int *printed)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_putnbr_hexa_printf(nbr / 16, printed);
		nbr = nbr % 16;
	}
	if (nbr <= 15)
		ft_putchar_printf(base[nbr], printed);
	return ;
}

void	ft_putnbr_hexa_maj_printf(unsigned int nbr, int *printed)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ft_putnbr_hexa_maj_printf(nbr / 16, printed);
		nbr = nbr % 16;
	}
	if (nbr <= 15)
		ft_putchar_printf(base[nbr], printed);
	return ;
}

void	ft_pointer_printf(unsigned long int pointer, int *printed, int *init)
{
	char	*base;

	base = "0123456789abcdef";
	if (*init == 0)
	{
		ft_putstr_printf("0x", printed);
		*init = 1;
	}
	if (pointer > 15)
	{
		ft_pointer_printf(pointer / 16, printed, init);
		pointer = pointer % 16;
	}
	if (pointer <= 15)
		ft_putchar_printf(base[pointer], printed);
	return ;
}
