/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:41:40 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 10:10:34 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_all_img(t_game *game_data)
{
	game_data->exit.img_close = ft_init_img(game_data,
			"./TEXTURES/exitportal_close.xpm");
	game_data->exit.img_open = ft_init_img(game_data,
			"./TEXTURES/exitportal_open.xpm");
	game_data->collec.img = ft_init_img(game_data, "./TEXTURES/Flint.xpm");
	game_data->img_floor = ft_init_img(game_data, "./TEXTURES/floor.xpm");
	game_data->wall.img_wall = ft_init_img(game_data, "./TEXTURES/wall.xpm");
	game_data->wall.img_wall2 = ft_init_img(game_data, "./TEXTURES/wall2.xpm");
	ft_init_img_player(game_data);
	if (!(game_data->exit.img_close && game_data->exit.img_open
			&& game_data->collec.img && game_data->img_floor
			&& game_data->wall.img_wall && game_data->wall.img_wall2))
		close_window(game_data);
	return ;
}

void	ft_display_map(t_map *new_map, t_game *game_data, int x, int y)
{
	while (y < new_map->height)
	{
		x = 0;
		while (x < new_map->width)
		{
			if (new_map->map[y][x] == '1')
				mlx_put_image_to_window(game_data->mlx_ptr, game_data->mlx_win,
					game_data->wall.img_wall->img, x * 48, y * 48);
			else if (new_map->map[y][x] == '0')
				mlx_put_image_to_window(game_data->mlx_ptr, game_data->mlx_win,
					game_data->img_floor->img, x * 48, y * 48);
			else if (new_map->map[y][x] == 'C')
				mlx_put_image_to_window(game_data->mlx_ptr, game_data->mlx_win,
					game_data->collec.img->img, x * 48, y * 48);
			x++;
		}
		y++;
	}
	ft_display_exit_player(game_data);
}

void	ft_init_all_data(t_game *game_data, t_map *new_map)
{
	game_data->collec = new_map->collectible;
	game_data->map = *new_map;
	game_data->exit.pos = new_map->exit;
	game_data->player.pos = new_map->player;
	game_data->player.collected = 0;
	game_data->exit.open = 0;
	game_data->movements = 0;
	game_data->on_end = 0;
	game_data->start = clock();
	game_data->on_frame = 0;
}

int	ft_check_symbol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'E' || str[i] == 'P'
			|| str[i] == 'C' || str[i] == '\n')
			i++;
		else
		{
			ft_error("Invalid symbol in the file only accept : \n");
			ft_error("'0, 1, C, P, E' \n");
			return (0);
		}
	}
	return (1);
}

int	ft_parse_map(char *map_str, t_map *new_map)
{
	int	error;

	error = 0;
	if (!ft_check_symbol(map_str))
		error += 1;
	if (!ft_check_player_exit_collectible(map_str, new_map))
		error += 1;
	if (!ft_check_map_is_rectangle(map_str, new_map))
		error += 1;
	else if (!ft_check_map_is_closed(new_map))
		error += 1;
	if (error)
		return (0);
	return (1);
}
