/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_search_path2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:04:08 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 10:08:54 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_random_dir(int possible_directions)
{
	if (possible_directions & (1 << 0))
		return (1);
	if (possible_directions & (1 << 1))
		return (2);
	if (possible_directions & (1 << 2))
		return (4);
	return (8);
}

void	ft_move_position(t_position *p, t_Direction dir)
{
	if (dir == LEFT)
		p->x -= 1;
	else if (dir == RIGHT)
		p->x += 1;
	else if (dir == UP)
		p->y -= 1;
	else if (dir == DOWN)
		p->y += 1;
}

int	ft_count_bit_1(int number)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 8)
	{
		if (number & (1 << i))
			count++;
		i++;
	}
	return (count);
}
