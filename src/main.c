/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:28:47 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:24:42 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map		map_design;
	t_hook_data	hook_data;

	(void)argc;
	if (check_ber(argv[1]) != 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("El fichero de entrada debe tener una extensión .ber\n",
			1);
		exit(0);
	}
	read_map(argv[1], &map_design);
	get_coin_num(&map_design);
	sl_put_player(&map_design);
	sl_path_check(&map_design, map_design.player_y, map_design.player_x);
	init_graphics(&map_design, &hook_data);
	return (0);
}
