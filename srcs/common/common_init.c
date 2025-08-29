/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:47:32 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 10:43:01 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_init_img(t_game *game_data, char *path_file)
{
	t_img	*new;

	new = ft_calloc(1, sizeof(t_img));
	new->img = mlx_xpm_file_to_image(game_data->mlx_ptr, path_file, &new->width,
			&new->height);
	if (!new->img)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void	ft_init_img_player(t_game *game_data)
{
	game_data->player.imgright = ft_init_img(game_data,
			"./TEXTURES/player_right.xpm");
	game_data->player.imgleft = ft_init_img(game_data,
			"./TEXTURES/player_left.xpm");
	game_data->player.imgfront = ft_init_img(game_data,
			"./TEXTURES/player_front.xpm");
	game_data->player.imgback = ft_init_img(game_data,
			"./TEXTURES/player_back.xpm");
	if (!(game_data->player.imgright && game_data->player.imgleft
			&& game_data->player.imgfront && game_data->player.imgback))
		close_window(game_data);
}

void	ft_init_new_map(t_map *new_map)
{
	new_map->height = 0;
	new_map->width = 0;
	new_map->map = NULL;
	new_map->collectible.positions = NULL;
	new_map->mob.positions = NULL;
	new_map->mob.number = 0;
	return ;
}
