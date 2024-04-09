/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:57:39 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/03 13:35:35 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_img
{
	void			*img;
	int				width;
	int				height;
}					t_img;

typedef struct s_wall
{
	t_img			*img_wall;
	t_img			*img_wall2;
	t_img			*img_wall3;
	t_img			*img_wall4;
	int				number;
	t_position		*positions;
}					t_wall;

typedef struct s_collectible
{
	int				number;
	t_position		*positions;
	t_img			*img;
}					t_collectible;

typedef struct s_mob
{
	int				number;
	t_position		*positions;
	t_img			*img;
}					t_mob;

typedef struct s_map
{
	int				width;
	int				height;
	t_position		player;
	t_position		exit;
	t_collectible	collectible;
	t_mob			mob;
	char			**map;
}					t_map;

typedef struct s_player
{
	int				collected;
	t_position		pos;
	t_img			*imgright;
	t_img			*imgleft;
	t_img			*imgfront;
	t_img			*imgback;
}					t_player;

typedef struct s_exit
{
	int				open;
	t_position		pos;
	t_img			*img_open;
	t_img			*img_close;

}					t_exit;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_img			*img_floor;
	t_img			*img_end;
	t_wall			wall;
	t_mob			mob;
	t_collectible	collec;
	t_player		player;
	t_exit			exit;
	t_map			map;
	long			start;
	int				movements;
	int				on_end;
	int				on_frame;
}					t_game;

typedef struct s_end_game
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_img			*img;
}					t_end_game;

typedef enum e_direction
{
	LEFT = 1,
	RIGHT = 2,
	UP = 4,
	DOWN = 8,
}					t_Direction;

// COMMON PART-----------------------------------

// common_close
void				free_all(t_game *game);
int					close_window(t_game *game);

// common_free
void				free_img(t_game *game_data);
void				free_map(t_map *new_map, int flag);
void				free_tab(char **str);

// common_parsing
int					ft_check_file_format(char *path);
char				*ft_collect_map(int fd);
int					ft_check_player_exit_collectible(char *str, t_map *new_map);

// common_parsing2
int					ft_check_map_is_rectangle(char *map_str, t_map *new_map);
int					ft_check_map_is_closed(t_map *new_map);

// common_init
t_img				*ft_init_img(t_game *game_data, char *path_file);
void				ft_init_img_player(t_game *game_data);
void				ft_init_new_map(t_map *new_map);

// common_search_path
int					ft_count_space(t_map *new_map);
int					ft_on_path(t_Direction d, t_position current_pos,
						t_position *path, int path_len);
int					ft_is_valid_path(t_map *new_map, t_position *path,
						int path_len, t_position *open_nodes);

// common_search_path2
int					ft_random_dir(int possible_directions);
void				ft_move_position(t_position *p, t_Direction dir);
int					ft_count_bit_1(int number);

// common_utils
void				ft_end_game(int x, int y, char *path, t_game *game);
void				ft_error(char *str);
void				ft_display_exit_player(t_game *game_data);
void				ft_fill_map(t_map *new_map, int x, int y, int c);
void				open_the_portal(t_game *game, int x, int y);

// MANDATORY PART---------------------------------------------------------------
// search_path
int					ft_check_path(t_map *new_map);

// init_game
void				ft_init_all_img(t_game *game_data);
void				ft_display_map(t_map *new_map, t_game *game_data, int x,
						int y);
void				ft_init_all_data(t_game *game_data, t_map *new_map);
int					ft_check_symbol(char *str);
int					ft_parse_map(char *map_str, t_map *new_map);

// game
void				ft_gaming(t_game *game_data, t_map *new_map);
void				ft_start_game(t_map *new_map);

// move
void				move_up(t_game *game);
void				move_down(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);

// player_action
void				ft_move_player_at(int x, int y, t_game *game,
						t_img *img_dir);
void				ft_move_player_at_from_e(int x, int y, t_game *game,
						t_img *img_dir);
int					key_hook(int keycode, t_game *game);

// BONUS------------------------------------------------------------------
// bonus
void				ft_print_mov_on_display(t_game *game);
void				ft_fill_mob(t_map *new_map, int x, int y);
void				ft_fill_wall_data(t_game *game_data);

// wall_animation
void				ft_moove_wall(t_game *game_data, t_img *wall);
int					ft_animate_wall(t_game *game_data);

// search_path_bonus
int					ft_check_path_bonus(t_map *new_map);

// init_game_bonus
void				ft_init_all_img_bonus(t_game *game_data);
void				ft_display_map_bonus(t_map *new_map, t_game *game_data,
						int x, int y);
void				ft_init_all_data_bonus(t_game *game_data, t_map *new_map);
int					ft_check_symbol_bonus(char *str);
int					ft_parse_map_bonus(char *map_str, t_map *new_map);

// game_bonus
void				ft_gaming_bonus(t_game *game_data, t_map *new_map);
void				ft_start_game_bonus(t_map *new_map);

// move_bonus
void				move_up_bonus(t_game *game);
void				move_down_bonus(t_game *game);
void				move_left_bonus(t_game *game);
void				move_right_bonus(t_game *game);

// player_action_bonus
void				ft_end_game_bonus(int x, int y, char *path, t_game *game);
void				ft_move_player_at_bonus(int x, int y, t_game *game,
						t_img *img_dir);
void				ft_move_player_at_from_e_bonus(int x, int y, t_game *game,
						t_img *img_dir);
int					key_hook_bonus(int keycode, t_game *game);

#endif