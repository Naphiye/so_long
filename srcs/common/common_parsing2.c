/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_parsing2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:42:22 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/02 17:45:03 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_first_line_is_closed(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			ft_error("Map is not closed on the upperside \n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_last_line_is_closed(char **map, t_map *new_map)
{
	int	i;

	i = 0;
	while (map[new_map->height - 1][i])
	{
		if (map[new_map->height - 1][i] != '1')
		{
			ft_error("Map is not closed on the downside \n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_column_are_closed(char **map, t_map *new_map)
{
	int	y;
	int	error;

	y = 1;
	error = 0;
	while (map[y + 1])
	{
		if (map[y][0] != '1')
		{
			ft_error("Map is not closed on the leftside \n");
			error += 1;
		}
		if (map[y][new_map->width - 1] != '1')
		{
			ft_error("Map is not closed on the rightside \n");
			error += 1;
		}
		y++;
	}
	if (error)
		return (0);
	return (1);
}

int	ft_check_map_is_closed(t_map *new_map)
{
	int	error;

	error = 0;
	if (!ft_first_line_is_closed(new_map->map))
		error += 1;
	if (!ft_column_are_closed(new_map->map, new_map))
		error += 1;
	if (!ft_last_line_is_closed(new_map->map, new_map))
		error += 1;
	if (error)
		return (0);
	return (1);
}

int	ft_check_map_is_rectangle(char *map_str, t_map *new_map)
{
	int		i;
	size_t	len_ref;

	new_map->map = ft_split(map_str, '\n');
	if (!new_map->map)
		free_map(new_map, 1);
	i = 0;
	len_ref = ft_strlen(new_map->map[0]);
	while (new_map->map[i])
	{
		if (ft_strlen(new_map->map[i]) != len_ref)
		{
			ft_error("Map must be rectangular \n");
			return (0);
		}
		i++;
	}
	if (i == 1)
	{
		ft_error("Map must be rectangular \n");
		return (0);
	}
	new_map->width = len_ref;
	new_map->height = i;
	return (1);
}
