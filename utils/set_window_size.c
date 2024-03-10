#include "../includes/map.h"
#include <stdio.h>

void	set_window_size(t_map_objs *data, t_map *table)
{
	(void)data;
	(void)table;
	data->window_width = table->cols * 107;
    data->window_height = table->rows * 107;
}
