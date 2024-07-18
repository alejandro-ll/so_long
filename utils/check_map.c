/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:08:17 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:25:27 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

int	check_walls(t_map *map_design)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_design->cols)
	{
		if (map_design->grid[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map_design->cols)
	{
		if (map_design->grid[map_design->rows - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < map_design->rows)
	{
		if (map_design->grid[j][0] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (j < map_design->rows)
	{
		if (map_design->grid[j][map_design->cols - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
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
	int		y;
	int		x;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	char	c;

	y = 0;
	x = 0;
	player_count = 0;
	collectible_count = 0;
	exit_count = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			c = map->grid[y][x];
			if (!is_valid_char(c))
				return (0);
			if (c == 'P')
				player_count++;
			if (c == 'C')
				collectible_count++;
			if (c == 'E')
				exit_count++;
			x++;
		}
		y++;
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
