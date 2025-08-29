/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:35:06 by fsalomon          #+#    #+#             */
/*   Updated: 2023/12/13 11:45:01 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(int n)
{
	int		i;
	int		j;
	int		divisor;
	long	nb2;

	nb2 = n;
	i = 0;
	if (nb2 < 0)
	{
		nb2 += 4294967295 + 1;
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
	return (ft_digits_nb_decimal(nb2));
}
