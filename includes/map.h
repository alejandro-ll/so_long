#ifndef MAP_H
# define MAP_H
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

typedef struct map_info
{
    int     rows;
    int     cols;
    char    **grid;
	int		coin_num;
} t_map;

typedef struct map_objs
{
    void 	*mlx;
    void 	*win;
    void 	*wall_img;
    void 	*floor_img;
    void    *ch_img;
    void	*coin_img;
    void	*exit_img;
    int		tile_size; // Tamaño de cada cuadrado
	int		window_width;
	int		window_height;
} t_map_objs;

typedef struct char_info
{
    int	x;
	int	y;
    int	new_x;
	int	new_y;
	int	coins;
	int	movs;
} t_char_info;

typedef struct hook_data
{
    t_char_info	*player;
    t_map 		*map;
    t_map_objs 	*m_objs;
} t_hook_data;

void	read_map(char *map_name, t_map *map_design);
void   	init_graphics(t_map *map_design, t_hook_data *hook_data);
void   	set_tile_size(t_map_objs *data, t_map *table);
void   	open_images(t_map_objs *data);
void   	draw_level(t_map_objs *data, t_map *table);
void	set_window_size(t_map_objs *data, t_map *table);
int		find_player_position(t_map *map, t_char_info *player);
int		handle_keypress(int keycode, t_hook_data *data);
void   	hook_load(t_char_info *player, t_map *map, t_map_objs *m_objs, t_hook_data *hook_data);
void	open_exit(t_map_objs *data);
void	pick_coin(t_hook_data *data, int new_x, int new_y);
void	update_map(t_map *map, t_char_info *player);
int		get_coin_num(t_map *map);
void	exit_object(t_hook_data *data, int new_x, int new_y);
void	check_map(t_map *map_design);
int		check_ber(char *filename);


#endif