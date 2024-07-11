#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdio.h>

void update_map(t_map *map, t_char_info *player)
{
    // Esta función actualiza el mapa después de que el jugador se ha movido.

    // Primero, restaura la casilla anterior donde estaba el jugador a su estado original.
    // En tu estructura t_map, supongamos que 'P' representa al jugador y '.' representa el suelo (grass).
    map->grid[player->y][player->x] = '0';

    // Luego, actualiza la posición del jugador en el mapa.
    map->grid[player->new_y][player->new_x] = 'P';

    player->x = player->new_x;
    player->y = player->new_y;

    // Puedes agregar lógica adicional aquí, como verificar si el jugador ha ganado o perdido.
}

int handle_keypress(int keycode, t_hook_data *data)
{
    int new_x = data->player->x;
    int new_y = data->player->y;

    if (keycode == 97) // Flecha izquierda
        new_x--;
    else if (keycode == 100) // Flecha derecha
        new_x++;
    else if (keycode == 115) // Flecha abajo
        new_y++;
    else if (keycode == 119) // Flecha arriba
        new_y--;
    if (new_x >= 0 && new_x < data->map->cols && new_y >= 0 && new_y < data->map->rows)
    {
        if (data->map->grid[new_y][new_x] == '0')
        {
            data->player->new_x = new_x;
            data->player->new_y = new_y;

            update_map(data->map, data->player);
            draw_level(data->m_objs, data->map);
            data->player->movs++;
            return (0);
        }
        pick_coin(data, new_x, new_y);
        exit_object(data, new_x, new_y);
    }
    return (0);
}

int find_player_position(t_map *map, t_char_info *player)
{
    int y = 0;
    int found = 0;

    while (y < map->rows && !found)
    {
        int x = 0;
        while (x < map->cols && !found)
        {
            if (map->grid[y][x] == 'P')
            {
                player->x = x;
                player->y = y;
                // Cambiar el carácter en la posición encontrada a '0' o lo que sea apropiado
                //map->grid[y][x] = '0';
                found = 1; // Posición del jugador encontrada
            }
            x++;
        }
        y++;
    }
    return found; // Devuelve 1 si se encontró al jugador en el mapa, 0 en caso contrario
}
