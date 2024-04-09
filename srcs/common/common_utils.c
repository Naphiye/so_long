/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:33:08 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 10:47:59 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
}

void	ft_display_exit_player(t_game *game_data)
{
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->mlx_win,
		game_data->exit.img_close->img, game_data->exit.pos.x * 48,
		game_data->exit.pos.y * 48);
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->mlx_win,
		game_data->player.imgfront->img, game_data->player.pos.x * 48,
		game_data->player.pos.y * 48);
}

void	ft_fill_map(t_map *new_map, int x, int y, int c)
{
	while (y < new_map->height)
	{
		x = 0;
		while (x < new_map->width)
		{
			if (new_map->map[y][x] == 'P')
			{
				new_map->player.x = x;
				new_map->player.y = y;
			}
			if (new_map->map[y][x] == 'E')
			{
				new_map->exit.x = x;
				new_map->exit.y = y;
			}
			if (c < new_map->collectible.number && new_map->map[y][x] == 'C')
			{
				new_map->collectible.positions[c].x = x;
				new_map->collectible.positions[c].y = y;
				c++;
			}
			x++;
		}
		y++;
	}
}

void	open_the_portal(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->exit.img_open->img, x * 48, y * 48);
	game->exit.open = 1;
}
