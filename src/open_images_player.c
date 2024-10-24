/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:20:20 by user              #+#    #+#             */
/*   Updated: 2024/10/24 14:04:15 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	open_character_base(t_map_objs *data)
{
	int	fd;

	fd = open("images/red_base.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening character base image file");
		exit(1);
	}
	data->ch_img_base = mlx_xpm_file_to_image(data->mlx, "images/red_base.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->ch_img_base)
	{
		perror("Error loading character base image");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	open_character_left(t_map_objs *data)
{
	int	fd;

	fd = open("images/red_left.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening character left image file");
		exit(1);
	}
	data->ch_img_left = mlx_xpm_file_to_image(data->mlx, "images/red_left.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->ch_img_left)
	{
		perror("Error loading character left image");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	open_character_right(t_map_objs *data)
{
	int	fd;

	fd = open("images/red_right.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening character right image file");
		exit(1);
	}
	data->ch_img_right = mlx_xpm_file_to_image(data->mlx,
			"images/red_right.xpm", &data->tile_size, &data->tile_size);
	if (!data->ch_img_right)
	{
		perror("Error loading character right image");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	open_character_up(t_map_objs *data)
{
	int	fd;

	fd = open("images/red_up.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening character up image file");
		exit(1);
	}
	data->ch_img_up = mlx_xpm_file_to_image(data->mlx, "images/red_up.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->ch_img_up)
	{
		perror("Error loading character up image");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	open_images_player(t_map_objs *data)
{
	open_character_base(data);
	open_character_left(data);
	open_character_right(data);
	open_character_up(data);
}
