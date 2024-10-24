/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:30:39 by allera-m          #+#    #+#             */
/*   Updated: 2024/10/24 09:23:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct map_info
{
	int			rows;
	int			cols;
	char		**grid;
	int			coin_num;
	int			player_x;
	int			player_y;
}				t_map;

typedef struct map_objs
{
	void		*mlx;
	void		*win;
	void		*wall_img;
	void		*floor_img;
	void		*ch_img_now;
	void		*coin_img;
	void		*exit_img;
	void		*enemy_img;
	void		*ch_img_left;
	void		*ch_img_left_two;
	void		*ch_img_right;
	void		*ch_img_right_two;
	void		*ch_img_up;
	void		*ch_img_base;
	int			right_animation_counter;
	int			left_animation_counter;
	int			tile_size;
	int			window_width;
	int			window_height;
}				t_map_objs;

typedef struct char_info
{
	int			x;
	int			y;
	int			new_x;
	int			new_y;
	int			coins;
	int			movs;
}				t_char_info;

typedef struct hook_data
{
	t_char_info	*player;
	t_map		*map;
	t_map_objs	*m_objs;
}				t_hook_data;

void			read_map(char *map_name, t_map *map_design);
void			init_graphics(t_map *map_design, t_hook_data *hook_data);
void			set_tile_size(t_map_objs *data, t_map *table);
void			open_images(t_map_objs *data);
void			draw_level(t_map_objs *data, t_map *table);
void			set_window_size(t_map_objs *data, t_map *table);
int				find_player_position(t_map *map, t_char_info *player);
int				handle_keypress(int keycode, t_hook_data *data);
void			hook_load(t_char_info *player, t_map *map, t_map_objs *m_objs,
					t_hook_data *hook_data);
void			open_exit(t_map_objs *data);
void			open_enemy(t_map_objs *data);
void			open_images_player(t_map_objs *data);
void			open_images_player_two(t_map_objs *data);
void			pick_coin(t_hook_data *data, int new_x, int new_y);
void			update_map(t_map *map, t_char_info *player);
int				get_coin_num(t_map *map);
void			exit_object(t_hook_data *data, int new_x, int new_y);
void			check_map(t_map *map_design);
int				check_ber(char *filename);
void			sl_path_check(t_map *map_design, int y, int x);
void			sl_put_player(t_map *map_design);
char			*read_file_to_buffer(char *full_path);
int				check_vertical_walls(t_map *map_design);
int				check_horizontal_walls(t_map *map_design);
int				count_chars_in_map(t_map *map, int *player_count,
					int *collectible_count, int *exit_count);
void			draw_screen_movs(t_map_objs *data, int movs);
#endif
