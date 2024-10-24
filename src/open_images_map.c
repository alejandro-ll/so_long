/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:29:01 by allera-m          #+#    #+#             */
/*   Updated: 2024/10/24 09:26:58 by user             ###   ########.fr       */
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
		exit(1);
	}
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "images/wall.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->wall_img)
	{
		perror("Error loading wall image");
		close(fd);
		exit(1);
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
		exit(1);
	}
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "images/grass.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->floor_img)
	{
		perror("Error loading floor image");
		close(fd);
		exit(1);
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
		exit(1);
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
	open_coin(data);
	open_exit(data);
	open_enemy(data);
	open_images_player(data);
	open_images_player_two(data);
	data->ch_img_now = data->ch_img_base;
	data->right_animation_counter = 0;
	data->left_animation_counter = 0;
}
