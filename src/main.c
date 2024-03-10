#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_map   	map_design;
    t_hook_data	hook_data;
	printf("numero de argumentos %d, aqui el name del programa %s" ,argc, argv[0]);
	read_map(argv[1], &map_design);
	get_coin_num(&map_design);
    init_graphics(&map_design, &hook_data);
    return 0;
}
