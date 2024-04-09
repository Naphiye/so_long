/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:37:55 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 12:18:52 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file_format(char *path)
{
	int	len;
	int	i;

	len = ft_strlen(path);
	i = 0;
	while (path[i] != '.')
		i++;
	if (ft_strncmp(".ber", &path[len - 4], 4) || ft_strncmp(".ber", &path[i],
			4))
	{
		ft_error("Wrong file format, file format must be '.ber' \n");
		return (0);
	}
	return (1);
}

static char	*ft_read_file(char *map, char *buf, int fd, int line_read)
{
	int	error;

	error = 0;
	buf = get_next_line(fd);
	while (buf)
	{
		map = ft_strjoin(map, buf);
		if (!map)
			return (NULL);
		free(buf);
		buf = get_next_line(fd);
		if (buf)
		{
			if (*buf == '\n')
				error++;
		}
		error++;
		line_read++;
	}
	free(buf);
	if (line_read != error)
		return (free(map), NULL);
	return (map);
}

char	*ft_collect_map(int fd)
{
	char	*map;
	char	*buf;
	int		line_read;

	map = ft_calloc(1, 1);
	if (!map)
		return (NULL);
	map[0] = 0;
	buf = NULL;
	line_read = 0;
	map = ft_read_file(map, buf, fd, line_read);
	if (!map)
	{
		ft_error("Empty line in file");
		return (NULL);
	}
	if (!map[0])
	{
		ft_error("Empty file");
		free(map);
		return (NULL);
	}
	return (map);
}

static int	ft_check_count_pec(int player, int exit, int collectible,
		t_map *new_map)
{
	if (player != 1 || exit != 1 || collectible < 1)
	{
		if (player > 1)
			ft_error("Map must contains only 1 player \n");
		else if (player < 1)
			ft_error("Map must contains at least 1 player \n");
		if (exit > 1)
			ft_error("Map must contains only 1 exit \n");
		else if (exit < 1)
			ft_error("Map must contains at least 1 exit \n");
		if (collectible < 1)
			ft_error("Map must contains at least 1 collectible \n");
		return (0);
	}
	new_map->collectible.number = collectible;
	return (1);
}

int	ft_check_player_exit_collectible(char *str, t_map *new_map)
{
	int	m;
	int	p;
	int	e;
	int	c;

	m = 0;
	p = 0;
	e = 0;
	c = 0;
	while (*str)
	{
		if (*str == 'E')
			e++;
		if (*str == 'P')
			p++;
		if (*str == 'C')
			c++;
		if (*str == 'M')
			m++;
		str++;
	}
	if (!ft_check_count_pec(p, e, c, new_map))
		return (0);
	new_map->mob.number = m;
	return (1);
}
