/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:27:56 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:24:11 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	draw_level(t_map_objs *data, t_map *table)
{
	void	*img;
	void	*img1;
	int		y;
	int		x;

	y = 0;
	while (y < table->rows)
	{
		x = 0;
		while (x < table->cols)
		{
			if (table->grid[y][x] == '1')
				img = data->wall_img;
			if (table->grid[y][x] == 'P')
			{
				img1 = data->floor_img;
				mlx_put_image_to_window(data->mlx, data->win, img1, x * 107, y
					* 107);
				img = data->ch_img;
			}
			if (table->grid[y][x] == '0')
				img = data->floor_img;
			if (table->grid[y][x] == 'C')
				img = data->coin_img;
			if (table->grid[y][x] == 'E')
				img = data->exit_img;
			mlx_put_image_to_window(data->mlx, data->win, img, x * 107, y
				* 107);
			x++;
		}
		y++;
	}
}
