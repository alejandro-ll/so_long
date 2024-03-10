#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void draw_level(t_map_objs *data, t_map *table)
{
    void    *img;
    void    *img1;
    int     y;
    int     x;

    y = 0;
    while (y < table->rows) { // Itera sobre todas las filas
        x = 0;
        while (x < table->cols) { // Itera sobre todas las columnas
            if (table->grid[y][x] == '1')
                img = data->wall_img;
            if (table->grid[y][x] == 'P')
            {
                img1 = data->floor_img;
                mlx_put_image_to_window(data->mlx, data->win, img1, x * 107, y * 107);
                img = data->ch_img; // Aquí asume que character_img es la imagen del personaje
            }
            if (table->grid[y][x] == '0')
                img = data->floor_img;
			if (table->grid[y][x] == 'C')
				img = data->coin_img;
            if (table->grid[y][x] == 'E')
                img = data->exit_img;
            mlx_put_image_to_window(data->mlx, data->win, img, x * 107, y * 107);
            x++;
        }
        y++;
    }
}
