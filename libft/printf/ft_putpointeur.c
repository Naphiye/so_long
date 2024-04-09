/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:15:35 by fsalomon          #+#    #+#             */
/*   Updated: 2023/12/13 11:46:09 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digits_nb_ptr(unsigned long long nb)
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

int	ft_putpointeur(unsigned long long pointeur, char c)
{
	int	i;

	i = 0;
	if (c == 'p')
	{
		if (pointeur == 0)
		{
			ft_putstr("(nil)");
			return (5);
		}
		write(1, "0x", 2);
		i += 2;
	}
	i += ft_digits_nb_ptr(pointeur);
	ft_putnbr_hexa((unsigned long long)pointeur, c);
	return (i);
}
