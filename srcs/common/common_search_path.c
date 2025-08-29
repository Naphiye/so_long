/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_search_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:00:20 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/02 18:08:37 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_space(t_map *new_map)
{
	int	zeros;
	int	y;
	int	x;

	y = 0;
	x = 0;
	zeros = 0;
	while (y < new_map->height)
	{
		x = 0;
		while (x < new_map->width)
		{
			if (new_map->map[y][x] == '0')
				zeros++;
			x++;
		}
		y++;
	}
	return (zeros);
}

int	ft_on_path(t_Direction d, t_position current_pos, t_position *path,
		int path_len)
{
	int	i;

	i = 0;
	ft_move_position(&current_pos, d);
	while (i < path_len)
	{
		if (current_pos.x == path[i].x && current_pos.y == path[i].y)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_collectibles_on_path(t_map *new_map, t_position *path,
		int path_len)
{
	int	i;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (i < path_len)
	{
		if (new_map->map[path[i].y][path[i].x] == 'C')
			collectibles++;
		i++;
	}
	return (collectibles);
}

static int	ft_exit_on_path(t_map *new_map, t_position *path, int path_len)
{
	int	i;

	i = 0;
	while (i < path_len)
	{
		if (new_map->map[path[i].y][path[i].x] == 'E')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_valid_path(t_map *new_map, t_position *path, int path_len,
		t_position *open_nodes)
{
	int	valid;

	valid = 1;
	if (ft_count_collectibles_on_path(new_map, path,
			path_len) != new_map->collectible.number)
	{
		ft_error("Map must contains a valid path to all the collectibles. \n");
		valid = 0;
	}
	if (!ft_exit_on_path(new_map, path, path_len))
	{
		ft_error("Map must contains a valid path to the exit. \n");
		valid = 0;
	}
	free(path);
	free(open_nodes);
	return (valid);
}
