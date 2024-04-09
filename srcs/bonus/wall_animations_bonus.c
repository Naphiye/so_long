/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_animations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:21:31 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 11:24:16 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moove_wall(t_game *game_data, t_img *wall)
{
	int	i;

	i = 0;
	while (i < game_data->wall.number)
	{
		mlx_put_image_to_window(game_data->mlx_ptr, game_data->mlx_win, wall,
			game_data->wall.positions[i].x * 48, game_data->wall.positions[i].y
			* 48);
		i++;
	}
	mlx_do_sync(game_data->mlx_ptr);
}

int	ft_animate_wall2(t_game *game_data)
{
	long	time;
	long	depart;
	long	fin;

	time = 500000;
	depart = game_data->start;
	fin = clock();
	if (game_data->on_frame == 2 && (fin - depart > time)
		&& game_data->on_end == 0)
	{
		ft_moove_wall(game_data, game_data->wall.img_wall4->img);
		game_data->on_frame = 3;
		game_data->start = clock();
	}
	else if (game_data->on_frame == 3 && (fin - depart > time)
		&& game_data->on_end == 0)
	{
		ft_moove_wall(game_data, game_data->wall.img_wall->img);
		game_data->on_frame = 0;
		game_data->start = clock();
	}
	return (0);
}

int	ft_animate_wall(t_game *game_data)
{
	long	time;
	long	depart;
	long	fin;

	time = 500000;
	depart = game_data->start;
	fin = clock();
	if (game_data->on_frame == 0 && (fin - depart > time)
		&& game_data->on_end == 0)
	{
		ft_moove_wall(game_data, game_data->wall.img_wall2->img);
		game_data->on_frame = 1;
		game_data->start = clock();
	}
	else if (game_data->on_frame == 1 && (fin - depart > time)
		&& game_data->on_end == 0)
	{
		ft_moove_wall(game_data, game_data->wall.img_wall3->img);
		game_data->on_frame = 2;
		game_data->start = clock();
	}
	ft_animate_wall2(game_data);
	return (0);
}
