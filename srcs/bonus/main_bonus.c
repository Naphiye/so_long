/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:34:41 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 10:32:44 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_input_bonus(char *path, t_map *new_map)
{
	char	*map_str;
	int		fd;

	if (!ft_check_file_format(path))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 1)
	{
		ft_error("Failing opening the file \n");
		return (0);
	}
	map_str = ft_collect_map(fd);
	if (!map_str)
		return (0);
	close(fd);
	if (!ft_parse_map_bonus(map_str, new_map))
	{
		free(map_str);
		return (0);
	}
	free(map_str);
	if (!ft_check_path_bonus(new_map))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	new_map;

	if (argc != 2)
	{
		ft_error("This program works with 1 argument '.ber' \n");
		return (0);
	}
	else
	{
		ft_bzero(&new_map, sizeof(t_map));
		if (!ft_check_input_bonus(argv[1], &new_map))
			free_map(&new_map, 1);
		ft_start_game_bonus(&new_map);
	}
	free_map(&new_map, 1);
	return (0);
}
