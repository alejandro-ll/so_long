/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images_map_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:28:54 by allera-m          #+#    #+#             */
/*   Updated: 2024/10/24 14:03:53 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	open_exit(t_map_objs *data)
{
	int	fd;

	fd = open("images/exit.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening exit image file");
		exit(1);
	}
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "images/exit.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->exit_img)
	{
		perror("Error loading exit image");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	open_enemy(t_map_objs *data)
{
	int	fd;

	fd = open("images/enemigo.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening exit image file");
		exit(1);
	}
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, "images/enemigo.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->enemy_img)
	{
		perror("Error loading exit image");
		close(fd);
		exit(1);
	}
	close(fd);
}
