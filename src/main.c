#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_map   	map_design;
    t_hook_data	hook_data;

	(void)argc;
    if(check_ber(argv[1]) != 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("El fichero de entrada debe tener una extensión .ber\n", 1);
		exit(0);
	}
	read_map(argv[1], &map_design);
	get_coin_num(&map_design);
    init_graphics(&map_design, &hook_data);
    return 0;
}
