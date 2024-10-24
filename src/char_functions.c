/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:28:11 by allera-m          #+#    #+#             */
/*   Updated: 2024/10/24 14:45:52 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

void	walk_on_grass(t_hook_data *data, int new_x, int new_y)
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
}

void	update_map(t_map *map, t_char_info *player)
{
	map->grid[player->y][player->x] = '0';
	map->grid[player->new_y][player->new_x] = 'P';
	player->x = player->new_x;
	player->y = player->new_y;
}

void	calculate_new_position(int keycode, int *new_x, int *new_y,
		t_hook_data *data)
{
	if (keycode == 97)
	{
		(*new_x)--;
		if (data->m_objs->left_animation_counter % 2 == 0)
			data->m_objs->ch_img_now = data->m_objs->ch_img_left;
		else
			data->m_objs->ch_img_now = data->m_objs->ch_img_left_two;
		data->m_objs->left_animation_counter++;
	}
	else if (keycode == 100)
	{
		(*new_x)++;
		if (data->m_objs->right_animation_counter % 2 == 0)
			data->m_objs->ch_img_now = data->m_objs->ch_img_right;
		else
			data->m_objs->ch_img_now = data->m_objs->ch_img_right_two;
		data->m_objs->right_animation_counter++;
	}
	else
	{
		check_keyhandle_ext(keycode, new_y, data);
	}
}

int	handle_keypress(int keycode, t_hook_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player->x;
	new_y = data->player->y;
	calculate_new_position(keycode, &new_x, &new_y, data);
	if (new_x >= 0 && new_x < data->map->cols && new_y >= 0
		&& new_y < data->map->rows)
	{
		if (data->map->grid[new_y][new_x] == 'X')
		{
			ft_putstr_fd("\nGame Over\n", 1);
			exit(0);
		}
		if (data->map->grid[new_y][new_x] == '0')
		{
			walk_on_grass(data, new_x, new_y);
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
