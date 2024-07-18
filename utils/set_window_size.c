/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:29:27 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 22:30:40 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdio.h>

void	set_window_size(t_map_objs *data, t_map *table)
{
	(void)data;
	(void)table;
	data->window_width = table->cols * 107;
	data->window_height = table->rows * 107;
}
