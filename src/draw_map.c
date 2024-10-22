/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:27:56 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/23 18:10:23 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	*select_image(t_map_objs *data, char cell)
{
    if (cell == '1')
        return (data->wall_img);
    else if (cell == 'P')
        return (data->ch_img);
    else if (cell == '0')
        return (data->floor_img);
    else if (cell == 'C')
        return (data->coin_img);
    else if (cell == 'E')
        return (data->exit_img);
    else if (cell == 'X')
        return (data->enemy_img);
    return (NULL);
}

void	draw_screen_movs(t_map_objs *data, int movs)
{
	char	*movs_str;

	movs_str = ft_itoa(movs);
	mlx_string_put(data->mlx, data->win, 30, 20, 0x00000000, "Moves : ");
	mlx_string_put(data->mlx, data->win, 100, 20, 0x00000000, movs_str);
	free(movs_str);
}

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
			if (table->grid[y][x] == 'P')
			{
				img1 = data->floor_img;
				mlx_put_image_to_window(data->mlx, data->win, img1, x * 107, y
					* 107);
			}
			img = select_image(data, table->grid[y][x]);
			mlx_put_image_to_window(data->mlx, data->win, img, x * 107, y
				* 107);
			x++;
		}
		y++;
	}
}
