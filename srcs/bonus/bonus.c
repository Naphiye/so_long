/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:33:35 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 11:23:29 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fill_pos_wall(t_game *game_data, char **map)
{
	int	x;
	int	y;
	int	i;

	game_data->wall.positions = ft_calloc(game_data->wall.number,
			sizeof(t_position));
	if (!(game_data->wall.positions))
		close_window(game_data);
	y = 1;
	i = 0;
	while (map[y + 1])
	{
		x = 1;
		while (map[y][x + 1])
		{
			if (map[y][x] == '1')
			{
				game_data->wall.positions[i].x = x;
				game_data->wall.positions[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_fill_wall_data(t_game *game_data)
{
	int	x;
	int	y;

	y = 1;
	game_data->wall.number = 0;
	while (game_data->map.map[y + 1])
	{
		x = 1;
		while (game_data->map.map[y][x + 1])
		{
			if (game_data->map.map[y][x] == '1')
				game_data->wall.number++;
			x++;
		}
		y++;
	}
	ft_fill_pos_wall(game_data, game_data->map.map);
}

void	ft_print_mov_on_display(t_game *game)
{
	char	*movements;

	movements = NULL;
	movements = ft_itoa(game->movements);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->wall.img_wall->img, 48, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->wall.img_wall->img, 96, 0);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 4, 24, 0xFF0000, "step");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 48, 24, 0xFF0000, movements);
	free(movements);
}

void	ft_fill_mob(t_map *new_map, int x, int y)
{
	int	m;

	m = 0;
	while (y < new_map->height)
	{
		x = 0;
		while (x < new_map->width)
		{
			if (m < new_map->mob.number && new_map->map[y][x] == 'M')
			{
				new_map->mob.positions[m].x = x;
				new_map->mob.positions[m].y = y;
				m++;
			}
			x++;
		}
		y++;
	}
}
