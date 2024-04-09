/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:59:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 10:47:45 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_game(int x, int y, char *path, t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	game->mlx_win = mlx_new_window(game->mlx_ptr, y, x, "END");
	if (!game->mlx_win)
	{
		close_window(game);
	}
	game->img_end = ft_calloc(1, sizeof(t_img));
	game->img_end->img = mlx_xpm_file_to_image(game->mlx_ptr, path, &y, &x);
	if (!game->img_end->img)
		close_window(game);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_end->img, 0,
		0);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, close_window, game);
}

void	ft_move_player_at(int x, int y, t_game *game, t_img *img_dir)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_floor->img,
		game->player.pos.x * 48, game->player.pos.y * 48);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img_dir, x * 48, y
		* 48);
	game->player.pos.x = x;
	game->player.pos.y = y;
	if (game->map.map[y][x] == 'C')
	{
		game->player.collected++;
		game->map.map[y][x] = '0';
	}
	if (game->player.collected == game->collec.number)
		open_the_portal(game, game->exit.pos.x, game->exit.pos.y);
	game->movements++;
	ft_printf("\r %d", game->movements);
}

void	ft_move_player_at_from_e(int x, int y, t_game *game, t_img *img_dir)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->exit.img_close->img, game->exit.pos.x * 48, game->exit.pos.y
		* 48);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img_dir, x * 48, y
		* 48);
	game->player.pos.x = x;
	game->player.pos.y = y;
	if (game->map.map[y][x] == 'C')
	{
		game->player.collected++;
		game->map.map[y][x] = '0';
	}
	if (game->player.collected == game->collec.number)
		open_the_portal(game, game->exit.pos.x, game->exit.pos.y);
	game->movements++;
	ft_printf("\r %d", game->movements);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if ((keycode == 65362 || keycode == 119) && !game->on_end)
		move_up(game);
	else if ((keycode == 65361 || keycode == 97) && !game->on_end)
		move_left(game);
	else if ((keycode == 65363 || keycode == 100) && !game->on_end)
		move_right(game);
	else if ((keycode == 65364 || keycode == 115) && !game->on_end)
		move_down(game);
	return (0);
}
