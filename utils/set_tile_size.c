/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tile_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:29:22 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/22 14:29:54 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

void	set_tile_size(t_map_objs *data, t_map *table)
{
	int	min_tile_size_width;
	int	min_tile_size_height;

	min_tile_size_width = data->window_width / table->cols;
	min_tile_size_height = data->window_height / table->rows;
	if (min_tile_size_width < min_tile_size_height)
		data->tile_size = min_tile_size_width;
	else
		data->tile_size = min_tile_size_height;
}
