/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:23:54 by allera-m          #+#    #+#             */
/*   Updated: 2024/10/24 14:06:03 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'X');
}

int	count_chars_in_map(t_map *map, int *player_count, int *collectible_count,
	int *exit_count)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			c = map->grid[y][x];
			if (!is_valid_char(c))
				return (0);
			if (c == 'P')
				(*player_count)++;
			if (c == 'C')
				(*collectible_count)++;
			if (c == 'E')
				(*exit_count)++;
			x++;
		}
		y++;
	}
	return (1);
}
