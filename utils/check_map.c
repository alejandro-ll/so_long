/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:08:17 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/22 19:14:18 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

int	check_walls(t_map *map_design)
{
	if (!check_horizontal_walls(map_design))
		return (0);
	if (!check_vertical_walls(map_design))
		return (0);
	return (1);
}

int	is_rectangle(t_map *map)
{
	int	i;
	int	row_length;

	i = 0;
	if (map->rows > 0 && map->cols > 0)
	{
		while (i < map->rows)
		{
			row_length = 0;
			while (map->grid[i][row_length] != '\0')
			{
				row_length++;
			}
			if (row_length != map->cols)
				return (0);
			i++;
		}
		if (map->rows == map->cols)
			return (0);
		return (1);
	}
	return (0);
}

int	check_chars(t_map *map)
{
	int	player_count;
	int	collectible_count;
	int	exit_count;

	player_count = 0;
	collectible_count = 0;
	exit_count = 0;
	if (!count_chars_in_map(map, &player_count, &collectible_count,
			&exit_count))
	{
		return (0);
	}
	if (player_count != 1)
		return (0);
	if (collectible_count < 1)
		return (0);
	if (exit_count != 1)
		return (0);
	return (1);
}

void	check_map(t_map *map_design)
{
	if (is_rectangle(map_design) != 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("\nMapa incorrecto (cuadrado)\n", 1);
		exit(0);
	}
	if (check_walls(map_design) != 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("\nMapa incorrecto en cuanto a paredes y muros\n", 1);
		exit(0);
	}
	if (check_chars(map_design) != 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("\nMapa incorrecto en cuanto a figuras\n", 1);
		exit(0);
	}
}
