/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:39:54 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 11:54:49 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_bonus(t_game *game_data)
{
	if (game_data->mob.img)
	{
		if (game_data->mob.img)
			mlx_destroy_image(game_data->mlx_ptr, game_data->mob.img->img);
		if (game_data->mob.img)
			free(game_data->mob.img);
	}
}

static void	free_data(t_game *game_data)
{
	free(game_data->wall.positions);
	if (game_data->mob.positions)
		free(game_data->mob.positions);
	free(game_data->collec.positions);
}

void	free_all(t_game *game)
{
	free_img(game);
	free_bonus(game);
	free_tab(game->map.map);
	free_data(game);
	return ;
}

int	close_window(t_game *game)
{
	free_all(game);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}
