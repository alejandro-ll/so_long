#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdio.h>

//These functions are to load an auxiliary structure to control easier for the key_hook function, (by passing the arguments)

void    hook_load(t_char_info *player, t_map *map, t_map_objs *m_objs, t_hook_data *hook_data)
{
	hook_data->player = player;
	hook_data->map = map;
	hook_data->m_objs = m_objs;
    hook_data->player->coins = 0;
    hook_data->player->movs = 0;
}