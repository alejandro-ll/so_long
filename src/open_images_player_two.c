/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images_player_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:08:05 by user              #+#    #+#             */
/*   Updated: 2024/10/24 09:11:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	open_character_left_two(t_map_objs *data)
{
	int	fd;

	fd = open("images/red_left_2.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening character left two image file");
		exit(1);
	}
	data->ch_img_left_two = mlx_xpm_file_to_image(data->mlx, "images/red_left_2.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->ch_img_left_two)
	{
		perror("Error loading character left two image");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	open_character_right_two(t_map_objs *data)
{
	int	fd;

	fd = open("images/red_right_2.xpm", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening character right two image file");
		exit(1);
	}
	data->ch_img_right_two = mlx_xpm_file_to_image(data->mlx, "images/red_right_2.xpm",
			&data->tile_size, &data->tile_size);
	if (!data->ch_img_right_two)
	{
		perror("Error loading character right two image");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	open_images_player_two(t_map_objs *data)
{
	open_character_left_two(data);
	open_character_right_two(data);
}