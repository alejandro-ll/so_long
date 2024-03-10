#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdio.h>

void	exit_object(t_hook_data *data, int new_x, int new_y)
{
	if (data->player->coins == data->map->coin_num)
	{
	    if (data->map->grid[new_y][new_x] == 'E')
	    {
	        data->player->new_x = new_x;
	        data->player->new_y = new_y;
		    (data->player->coins)++;
	        update_map(data->map, data->player);
	        draw_level(data->m_objs, data->map);
            data->player->movs++;
        	printf("\nnúmero de movimientos realizados: %d\n", data->player->movs);
            exit(0);
	    }
    }
}