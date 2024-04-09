/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:13:04 by fsalomon          #+#    #+#             */
/*   Updated: 2023/12/13 11:46:54 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdigits(int n, char c)
{
	char	d;

	d = n + 48;
	if (n >= 10)
	{
		if (c == 'x' || c == 'p')
			d += 39;
		if (c == 'X')
			d += 7;
	}
	write(1, &d, 1);
}

static int	ft_digits_nb_hexa( long nb)
{
	int	digits_nb;

	digits_nb = 1;
	while ((nb / 16) > 0)
	{
		digits_nb++;
		nb /= 16;
	}
	return (digits_nb);
}

void	ft_putnbr_hexa( unsigned long long n, char c)
{
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, c);
		ft_putdigits((n % 16), c);
	}
	if (n < 16)
		ft_putdigits(n, c);
	return ;
}

int	ft_put_hexa( unsigned int hexa, char c)
{
	int	i;

	i = 0;
	if (c == 'p')
	{
		if (hexa == 0)
		{
			ft_putstr("(nil)");
			return (5);
		}
		write(1, "0x", 2);
		i += 2;
	}
	i += ft_digits_nb_hexa(hexa);
	ft_putnbr_hexa((long)hexa, c);
	return (i);
}
