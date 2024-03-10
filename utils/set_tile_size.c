#include "../includes/map.h"
#include <stdio.h>

void print_matrix(t_map *table)
{
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%c ", table->grid[i][j]);
        }
        printf("\n");
    }
}

void print_tile_info(t_map_objs *data, int min_tile_size_width, int min_tile_size_height) {
    printf("tile_size: %d\n", data->tile_size);
    printf("min_tile_size_width: %d\n", min_tile_size_width);
    printf("min_tile_size_height: %d\n", min_tile_size_height);
}

void set_tile_size(t_map_objs *data, t_map *table) {
    int min_tile_size_width; 
    int min_tile_size_height; 


    printf("numero de filas-> %d, numero de columnas %d", table->rows, table->cols);
    min_tile_size_width = data->window_width / table->cols;
    min_tile_size_height = data->window_height / table->rows;
    data->tile_size = min_tile_size_width < min_tile_size_height ? min_tile_size_width : min_tile_size_height;

    print_matrix(table);
    print_tile_info(data, min_tile_size_width, min_tile_size_height);
}