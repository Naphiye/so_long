/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:49:38 by fsalomon          #+#    #+#             */
/*   Updated: 2023/12/13 11:45:50 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose_format(char c, va_list list_arg)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar(va_arg(list_arg, int));
	else if (c == 's')
		size = ft_putstr(va_arg(list_arg, char *));
	else if (c == 'p')
		size = ft_putpointeur(va_arg(list_arg, unsigned long long), c);
	else if (c == 'd')
		size = ft_putnbr(va_arg(list_arg, int));
	else if (c == 'i')
		size = ft_putnbr(va_arg(list_arg, int));
	else if (c == 'u')
		size = ft_put_unsigned_nbr(va_arg(list_arg, int));
	else if (c == 'x')
		size = ft_put_hexa(va_arg(list_arg, int), c);
	else if (c == 'X')
		size = ft_put_hexa(va_arg(list_arg, int), c);
	else if (c == '%')
		size = ft_putchar(c);
	return (size);
}

int	ft_printf(const char *argv, ...)
{
	va_list	list_argv;
	int		i;
	int		size;

	va_start(list_argv, argv);
	i = 0;
	size = 0;
	if (!argv)
		return (-1);
	while (argv[i])
	{
		if (argv[i] == '%')
		{
			i++;
			size += ft_choose_format(argv[i], list_argv);
		}
		else
		{
			ft_putchar(argv[i]);
			size++;
		}
		i++;
	}
	va_end(list_argv);
	return (size);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	me;
// 	int	real;

// 	real = printf(0);
// 	printf("\n");
// 	me = ft_printf(0);
// 	printf("\n");
// 	printf(" me = %d real = %d \n", me, real);
// }
