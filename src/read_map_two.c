/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allera-m <allera-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:07:25 by allera-m          #+#    #+#             */
/*   Updated: 2024/07/23 18:44:25 by allera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	buffer_join(char **buffer, char *line)
{
	char	*temp;

	temp = ft_strjoin(*buffer, line);
	free(*buffer);
	*buffer = temp;
}

char	*read_file_to_buffer(char *full_path)
{
	int		fd;
	char	*line;
	char	*buffer;

	buffer = NULL;
	fd = open(full_path, O_RDONLY);
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
	return (buffer);
}
