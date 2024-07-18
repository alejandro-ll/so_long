#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdio.h>

void	pick_coin(t_hook_data *data, int new_x, int new_y)
{
	if (data->map->grid[new_y][new_x] == 'C')
	{
	    data->player->new_x = new_x;
	    data->player->new_y = new_y;
		(data->player->coins)++;
	    update_map(data->map, data->player);
	    draw_level(data->m_objs, data->map);
		data->player->movs++;
        //printf("\nnumero de monedas totales: %d, numero de monedas recogidas: %d\n", data->map->coin_num, data->player->coins);
		//printf("\nnúmero de movimientos realizados: %d\n", data->player->movs);
	}
}

int	get_coin_num(t_map *map)
{
	int num_coins;
	int	y;

	num_coins = 0;
	y = 0;
	while (y < map->rows)
	{
        int x = 0;
        while (x < map->cols)
		{
            if (map->grid[y][x] == 'C')
                num_coins++;
            x++;
        }
        y++;
    }
	map->coin_num = num_coins;
    return num_coins;
}
