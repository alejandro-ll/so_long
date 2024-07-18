/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:28:21 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:23:13 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

void	exit_object(t_hook_data *data, int new_x, int new_y)
{
	if (data->player->coins == data->map->coin_num)
	{
		if (data->map->grid[new_y][new_x] == 'E')
		{
			write(1, "\b\b\b\b\b\b\b\b\b\b", 10);
			data->player->new_x = new_x;
			data->player->new_y = new_y;
			(data->player->coins)++;
			update_map(data->map, data->player);
			draw_level(data->m_objs, data->map);
			data->player->movs++;
			write(1, "\nYour finish with ", 18);
			ft_putnbr_fd(data->player->movs, 1);
			write(1, " moves\n", 7);
			exit(0);
		}
	}
}
