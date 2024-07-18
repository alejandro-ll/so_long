/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:07:28 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/18 23:44:15 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

int	get_number_of_rows(char **array)
{
	int	count;

	count = 0;
	if (array)
	{
		while (array[count])
		{
			count++;
		}
	}
	return (count);
}

int	get_number_of_cols(char **array)
{
	int	max_cols;
	int	i;
	int	current_cols;

	max_cols = 0;
	if (array)
	{
		i = 0;
		while (array[i])
		{
			current_cols = 0;
			while (array[i][current_cols])
				current_cols++;
			if (current_cols > max_cols)
				max_cols = current_cols;
			i++;
		}
	}
	return (max_cols);
}

void	buffer_join(char **buffer, char *line)
{
	char	*temp;

	temp = ft_strjoin(*buffer, line);
	free(*buffer);
	*buffer = temp;
}

void	fill_map_struct(char *buffer, t_map *map_design)
{
	map_design->grid = ft_split(buffer, '\n');
	map_design->rows = get_number_of_rows(map_design->grid);
	map_design->cols = get_number_of_cols(map_design->grid);
}

void	read_map(char *map_name, t_map *map_design)
{
	char	*source_link;
	int		fd;
	char	*line;
	char	*buffer;
	char	*full_path;

	source_link = "maps/";
	buffer = NULL;
	full_path = ft_strjoin(source_link, map_name);
	fd = open(full_path, O_RDONLY);
	free(full_path);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (buffer == NULL)
			buffer = ft_strdup(line);
		else
			buffer_join(&buffer, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fill_map_struct(buffer, map_design);
	free(buffer);
	check_map(map_design);
}
