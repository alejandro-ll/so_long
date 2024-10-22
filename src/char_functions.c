/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:28:11 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:27:25 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

void	update_map(t_map *map, t_char_info *player)
{
	map->grid[player->y][player->x] = '0';
	map->grid[player->new_y][player->new_x] = 'P';
	player->x = player->new_x;
	player->y = player->new_y;
}

void	calculate_new_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == 97)
		(*new_x)--;
	else if (keycode == 100)
		(*new_x)++;
	else if (keycode == 115)
		(*new_y)++;
	else if (keycode == 119)
		(*new_y)--;
}

int	handle_keypress(int keycode, t_hook_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player->x;
	new_y = data->player->y;
	calculate_new_position(keycode, &new_x, &new_y);
	if (new_x >= 0 && new_x < data->map->cols && new_y >= 0
		&& new_y < data->map->rows)
	{
		if (data->map->grid[new_y][new_x] == '0')
		{
			write(1, "\b\b\b\b\b\b\b\b\b\b", 11);
			data->player->new_x = new_x;
			data->player->new_y = new_y;
			update_map(data->map, data->player);
			draw_level(data->m_objs, data->map);
			data->player->movs++;
			draw_screen_movs(data->m_objs, data->player->movs);
			write(1, "Moves : ", 9);
			ft_putnbr_fd(data->player->movs, 1);
			return (0);
		}
		pick_coin(data, new_x, new_y);
		exit_object(data, new_x, new_y);
	}
	return (0);
}

int	find_player_position(t_map *map, t_char_info *player)
{
	int	y;
	int	found;
	int	x;

	y = 0;
	found = 0;
	while (y < map->rows && !found)
	{
		x = 0;
		while (x < map->cols && !found)
		{
			if (map->grid[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
				found = 1;
			}
			x++;
		}
		y++;
	}
	return (found);
}
