/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:29:05 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:25:03 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

void	pick_coin(t_hook_data *data, int new_x, int new_y)
{
	if (data->map->grid[new_y][new_x] == 'C')
	{
		data->player->new_x = new_x;
		data->player->new_y = new_y;
		(data->player->coins)++;
		update_map(data->map, data->player);
		draw_level(data->m_objs, data->map);
		data->player->movs++;
	}
}

int	get_coin_num(t_map *map)
{
	int	num_coins;
	int	y;
	int	x;

	num_coins = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'C')
				num_coins++;
			x++;
		}
		y++;
	}
	map->coin_num = num_coins;
	return (num_coins);
}
