/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:28:31 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:23:23 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

void	hook_load(t_char_info *player, t_map *map, t_map_objs *m_objs,
		t_hook_data *hook_data)
{
	hook_data->player = player;
	hook_data->map = map;
	hook_data->m_objs = m_objs;
	hook_data->player->coins = 0;
	hook_data->player->movs = 0;
}
