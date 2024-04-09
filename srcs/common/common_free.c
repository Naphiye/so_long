/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:32:46 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 12:20:59 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_img_player(t_game *game_data)
{
	if (game_data->player.imgright)
		mlx_destroy_image(game_data->mlx_ptr, game_data->player.imgright->img);
	if (game_data->player.imgright)
		free(game_data->player.imgright);
	if (game_data->player.imgleft)
		mlx_destroy_image(game_data->mlx_ptr, game_data->player.imgleft->img);
	if (game_data->player.imgleft)
		free(game_data->player.imgleft);
	if (game_data->player.imgback)
		mlx_destroy_image(game_data->mlx_ptr, game_data->player.imgback->img);
	if (game_data->player.imgback)
		free(game_data->player.imgback);
	if (game_data->player.imgfront)
		mlx_destroy_image(game_data->mlx_ptr, game_data->player.imgfront->img);
	if (game_data->player.imgfront)
		free(game_data->player.imgfront);
}

static void	ft_free_img_wall(t_game *game_data)
{
	if (game_data->wall.img_wall)
		mlx_destroy_image(game_data->mlx_ptr, game_data->wall.img_wall->img);
	if (game_data->wall.img_wall)
		free(game_data->wall.img_wall);
	if (game_data->wall.img_wall2)
		mlx_destroy_image(game_data->mlx_ptr, game_data->wall.img_wall2->img);
	if (game_data->wall.img_wall2)
		free(game_data->wall.img_wall2);
	if (game_data->wall.img_wall3)
		mlx_destroy_image(game_data->mlx_ptr, game_data->wall.img_wall3->img);
	if (game_data->wall.img_wall3)
		free(game_data->wall.img_wall3);
	if (game_data->wall.img_wall4)
		mlx_destroy_image(game_data->mlx_ptr, game_data->wall.img_wall4->img);
	if (game_data->wall.img_wall4)
		free(game_data->wall.img_wall4);
}

void	free_img(t_game *game_data)
{
	if (game_data->exit.img_close)
		mlx_destroy_image(game_data->mlx_ptr, game_data->exit.img_close->img);
	if (game_data->exit.img_close)
		free(game_data->exit.img_close);
	if (game_data->exit.img_open)
		mlx_destroy_image(game_data->mlx_ptr, game_data->exit.img_open->img);
	if (game_data->exit.img_open)
		free(game_data->exit.img_open);
	if (game_data->collec.img)
		mlx_destroy_image(game_data->mlx_ptr, game_data->collec.img->img);
	if (game_data->collec.img)
		free(game_data->collec.img);
	if (game_data->img_floor)
		mlx_destroy_image(game_data->mlx_ptr, game_data->img_floor->img);
	if (game_data->img_floor)
		free(game_data->img_floor);
	if (game_data->img_end)
		mlx_destroy_image(game_data->mlx_ptr, game_data->img_end->img);
	if (game_data->img_end)
		free(game_data->img_end);
	ft_free_img_wall(game_data);
	ft_free_img_player(game_data);
}

void	free_map(t_map *new_map, int flag)
{
	if (new_map->map)
		free_tab(new_map->map);
	if (flag)
		exit(0);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}
