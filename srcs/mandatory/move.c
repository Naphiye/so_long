/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:18:41 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/02 15:31:08 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->map.map[y - 1][x] == '0' || game->map.map[y - 1][x] == 'C'
		|| game->map.map[y - 1][x] == 'P' || (game->map.map[y - 1][x] == 'E'
			&& !game->exit.open))
		ft_move_player_at(x, y - 1, game, game->player.imgback->img);
	else if (game->map.map[y - 1][x] == 'E' && game->exit.open)
	{
		game->on_end = 1;
		ft_end_game(423, 500, "TEXTURES/win.xpm", game);
	}
	if (game->map.map[y][x] == 'E' && !game->exit.open && (game->map.map[y
			- 1][x] != '1'))
		ft_move_player_at_from_e(x, y - 1, game, game->player.imgback->img);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->map.map[y + 1][x] == '0' || game->map.map[y + 1][x] == 'C'
		|| game->map.map[y + 1][x] == 'P' || (game->map.map[y + 1][x] == 'E'
			&& !game->exit.open))
		ft_move_player_at(x, y + 1, game, game->player.imgfront->img);
	else if (game->map.map[y + 1][x] == 'E' && game->exit.open)
	{
		game->on_end = 1;
		ft_end_game(423, 500, "TEXTURES/win.xpm", game);
	}
	if (game->map.map[y][x] == 'E' && !game->exit.open && (game->map.map[y
			+ 1][x] != '1'))
		ft_move_player_at_from_e(x, y + 1, game, game->player.imgfront->img);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->map.map[y][x - 1] == '0' || game->map.map[y][x - 1] == 'C'
		|| game->map.map[y][x - 1] == 'P' || (game->map.map[y][x - 1] == 'E'
			&& !game->exit.open))
		ft_move_player_at(x - 1, y, game, game->player.imgleft->img);
	else if (game->map.map[y][x - 1] == 'E' && game->exit.open)
	{
		game->on_end = 1;
		ft_end_game(423, 500, "TEXTURES/win.xpm", game);
	}
	if (game->map.map[y][x] == 'E' && !game->exit.open && (game->map.map[y][x
			- 1] != '1'))
		ft_move_player_at_from_e(x - 1, y, game, game->player.imgleft->img);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->map.map[y][x + 1] == '0' || game->map.map[y][x + 1] == 'C'
		|| game->map.map[y][x + 1] == 'P' || (game->map.map[y][x + 1] == 'E'
			&& !game->exit.open))
		ft_move_player_at(x + 1, y, game, game->player.imgright->img);
	else if (game->map.map[y][x + 1] == 'E' && game->exit.open)
	{
		game->on_end = 1;
		ft_end_game(423, 500, "TEXTURES/win.xpm", game);
	}
	if (game->map.map[y][x] == 'E' && !game->exit.open && (game->map.map[y][x
			+ 1] != '1'))
		ft_move_player_at_from_e(x + 1, y, game, game->player.imgright->img);
}
