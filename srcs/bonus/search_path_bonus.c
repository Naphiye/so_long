/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:56:45 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 11:24:05 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_can_go_bonus(t_Direction d, t_position current_pos, char **map)
{
	ft_move_position(&current_pos, d);
	if (map[current_pos.y][current_pos.x] == '1'
		|| map[current_pos.y][current_pos.x] == 'M')
		return (0);
	return (1);
}

static int	ft_which_directions_bonus(t_map *new_map, t_position current_pos,
		t_position *path, int path_len)
{
	int	left;
	int	right;
	int	up;
	int	down;

	left = LEFT;
	right = RIGHT;
	up = UP;
	down = DOWN;
	if (current_pos.x == 1 || !ft_can_go_bonus(LEFT, current_pos, new_map->map)
		|| ft_on_path(LEFT, current_pos, path, path_len))
		left = 0;
	if (current_pos.x == (*new_map).width - 2 || !ft_can_go_bonus(RIGHT,
			current_pos, new_map->map) || ft_on_path(RIGHT, current_pos, path,
			path_len))
		right = 0;
	if (current_pos.y == 1 || !ft_can_go_bonus(UP, current_pos, new_map->map)
		|| ft_on_path(UP, current_pos, path, path_len))
		up = 0;
	if (current_pos.y == (*new_map).height - 2 || !ft_can_go_bonus(DOWN,
			current_pos, new_map->map) || ft_on_path(DOWN, current_pos, path,
			path_len))
		down = 0;
	return (left + right + up + down);
}

static int	ft_explore_all_path_bonus(t_position *path, t_position *open_nodes,
		t_map *new_map, t_position *current_pos)
{
	int	open_nodes_len;
	int	path_len;
	int	dir_possible;

	path_len = 0;
	open_nodes_len = 0;
	while (1)
	{
		dir_possible = ft_which_directions_bonus(new_map, *current_pos, path,
				path_len);
		if (ft_count_bit_1(dir_possible) == 0)
		{
			if (open_nodes_len > 0)
				*current_pos = open_nodes[open_nodes_len--];
			else if (open_nodes_len == 0)
				return (ft_is_valid_path(new_map, path, path_len, open_nodes));
		}
		else
		{
			if (ft_count_bit_1(dir_possible) > 1)
				open_nodes[++open_nodes_len] = *current_pos;
			ft_move_position(current_pos, ft_random_dir(dir_possible));
			path[path_len++] = *current_pos;
		}
	}
}

static int	ft_search_path_bonus(t_map *new_map, t_position *current_pos)
{
	t_position	*path;
	t_position	*open_nodes;
	int			is_there_a_valid_path;

	path = ft_calloc((ft_count_space(new_map) + new_map->collectible.number)
			+ 2, sizeof(t_position));
	if (!path)
		return (0);
	open_nodes = ft_calloc((ft_count_space(new_map)
				+ new_map->collectible.number) + 2, sizeof(t_position));
	if (!open_nodes)
	{
		free(path);
		return (0);
	}
	is_there_a_valid_path = ft_explore_all_path_bonus(path, open_nodes, new_map,
			current_pos);
	return (is_there_a_valid_path);
}

int	ft_check_path_bonus(t_map *new_map)
{
	int			x;
	int			y;
	int			c;
	t_position	current_pos;

	x = 0;
	y = 0;
	c = 0;
	new_map->collectible.positions = ft_calloc(new_map->collectible.number,
			sizeof(t_position));
	new_map->mob.positions = ft_calloc(new_map->mob.number, sizeof(t_position));
	if (!(new_map->collectible.positions && new_map->mob.positions))
		return (0);
	ft_fill_map(new_map, x, y, c);
	ft_fill_mob(new_map, x, y);
	current_pos.x = new_map->player.x;
	current_pos.y = new_map->player.y;
	return (ft_search_path_bonus(new_map, &current_pos));
}
