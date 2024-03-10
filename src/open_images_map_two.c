#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	open_exit(t_map_objs *data)
{
    int fd;
    fd = open("images/exit.xpm", O_RDONLY); // Cambia "wall_image.xpm" por la ruta de tu imagen de pared
    if (fd == -1)
    {
        perror("Error opening exit image file");
    }
    data->exit_img = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm", &data->tile_size, &data->tile_size);
    if (!data->exit_img)
    {
        perror("Error loading exit image");
        close(fd);
    }
    close(fd);
}