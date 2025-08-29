/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:27:38 by fsalomon          #+#    #+#             */
/*   Updated: 2023/12/13 11:43:09 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdigits_decimal(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

int	ft_digits_nb_decimal(long nb)
{
	int	digits_nb;
	int	negatif_nb;

	digits_nb = 1;
	negatif_nb = 0;
	if (nb < 0)
	{
		negatif_nb = 1;
		nb = -nb;
	}
	while ((nb / 10) > 0)
	{
		digits_nb++;
		nb /= 10;
	}
	return (digits_nb + negatif_nb);
}

int	ft_putnbr(int n)
{
	int		i;
	int		j;
	int		divisor;
	long	nb2;

	nb2 = n;
	i = 0;
	if (nb2 < 0)
	{
		write(1, "-", 1);
		nb2 = -nb2;
	}
	while (i < ft_digits_nb_decimal(nb2))
	{
		j = 0;
		divisor = 1;
		while (j + i < (ft_digits_nb_decimal(nb2) - 1))
		{
			divisor *= 10;
			j++;
		}
		ft_putdigits_decimal((nb2 / divisor) % 10);
		i++;
	}
	return (ft_digits_nb_decimal(n));
}
