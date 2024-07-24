/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:29:27 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/24 21:26:52 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

void	set_window_size(t_map_objs *data, t_map *table)
{
	(void)data;
	(void)table;
	if (table->cols * 107 > 3840 || table->rows * 107 > 2160)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Se supera la resolución de la pantalla", 1);
		exit(1);
	}
	data->window_width = table->cols * 107;
	data->window_height = table->rows * 107;
}
