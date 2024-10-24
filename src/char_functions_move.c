/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:08:45 by allera-m          #+#    #+#             */
/*   Updated: 2024/10/24 14:45:08 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

void	check_keyhandle_ext(int keycode, int *new_y, t_hook_data *data)
{
	if (keycode == 115)
	{
		(*new_y)++;
		data->m_objs->ch_img_now = data->m_objs->ch_img_base;
	}
	else if (keycode == 119)
	{
		(*new_y)--;
		data->m_objs->ch_img_now = data->m_objs->ch_img_up;
	}
}
