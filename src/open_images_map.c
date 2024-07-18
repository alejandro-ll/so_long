/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:29:01 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:24:56 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	open_wall(t_map_objs *data)
{
	int	fd;

	fd = open("images/wall.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening wall image file");
	}
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->wall_img)
	{
		perror("Error loading wall image");
		close(fd);
	}
	close(fd);
}

void	open_floor(t_map_objs *data)
{
	int	fd;

	fd = open("images/grass.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening floor image file");
	}
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "images/grass.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->floor_img)
	{
		perror("Error loading floor image");
		close(fd);
	}
	close(fd);
}

void	open_player(t_map_objs *data)
{
	int	fd;

	fd = open("images/character.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening player image file");
	}
	data->ch_img = mlx_xpm_file_to_image(data->mlx, "images/character.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->ch_img)
	{
		perror("Error loading player image");
		close(fd);
	}
	close(fd);
}

void	open_coin(t_map_objs *data)
{
	int	fd;

	fd = open("images/coin.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening coin image file");
	}
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "images/coin.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->coin_img)
	{
		perror("Error loading coin image");
		close(fd);
	}
	close(fd);
}

void	open_images(t_map_objs *data)
{
	open_wall(data);
	open_floor(data);
	open_player(data);
	open_coin(data);
	open_exit(data);
}
