#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include "../libft/libft.h"
#include <stdio.h>

int get_number_of_rows(char **array) {
    int count = 0;
    if (array) {
        while (array[count]) {
            count++;
        }
    }
    return count;
}

// Función para obtener el número de columnas en un array de cadenas
int get_number_of_cols(char **array) {
    int max_cols = 0;
    if (array) {
        int i = 0;
        while (array[i]) {
            int current_cols = 0;
            while (array[i][current_cols])
                current_cols++;
            if (current_cols > max_cols)
                max_cols = current_cols;
            i++;
        }
    }
    return max_cols;
}

void    buffer_join(char **buffer, char *line)
{
    char *temp = ft_strjoin(*buffer, line);
    free(*buffer);
    *buffer = temp;
}

void    fill_map_struct(char *buffer, t_map *map_design)
{
    map_design->grid = ft_split(buffer, '\n');
    map_design->rows = get_number_of_rows(map_design->grid);
    map_design->cols = get_number_of_cols(map_design->grid);
}

void read_map(char *map_name, t_map *map_design)
{
    char    *source_link;
    int     fd;
    char    *line;
    char    *buffer;

    source_link = "maps/";
    buffer = NULL;
    fd = open(ft_strjoin(source_link, map_name), O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        if (buffer == NULL)
            buffer = ft_strdup(line);
        else
            buffer_join(&buffer, line);
        free(line);
    }
    close(fd);
    fill_map_struct(buffer, map_design);
}
