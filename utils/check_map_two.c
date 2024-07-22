/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:03:45 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/22 15:09:48 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	check_ber(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		return (0);
	}
	return (ft_strcmp(filename + len - 4, ".ber") == 0);
}

int	check_vertical_walls(t_map *map_design)
{
	int	j;

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

int	check_horizontal_walls(t_map *map_design)
{
	int	i;

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
	return (1);
}
