/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:19:17 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 09:41:55 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_gaming(t_game *game_data, t_map *new_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_init_all_data(game_data, new_map);
	ft_init_all_img(game_data);
	ft_display_map(new_map, game_data, x, y);
	mlx_hook(game_data->mlx_win, 2, 1L << 0, key_hook, game_data);
	mlx_hook(game_data->mlx_win, 17, 1L << 17, close_window, game_data);
	mlx_loop(game_data->mlx_ptr);
}

void	ft_start_game(t_map *new_map)
{
	t_game	game_data;

	ft_bzero(&game_data, sizeof(t_game));
	game_data.mlx_ptr = mlx_init();
	if (!game_data.mlx_ptr)
		return ;
	game_data.mlx_win = mlx_new_window(game_data.mlx_ptr, new_map->width * 48,
			new_map->height * 48, "SO LONG");
	if (!game_data.mlx_win)
	{
		mlx_destroy_display(game_data.mlx_ptr);
		free(game_data.mlx_ptr);
		return ;
	}
	ft_gaming(&game_data, new_map);
	free_all(&game_data);
	exit(0);
}
