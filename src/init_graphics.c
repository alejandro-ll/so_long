#include "../minilibx-linux/mlx.h"
#include "../includes/map.h"
#include <stdio.h>

int exit_hook(void)
{
    exit(0);
}

int key_hook(int keycode, t_hook_data *data)
{   
    if (keycode == 65307)
    {
        exit(0);
    }
    else if (keycode == 100 || keycode ==  97 || keycode == 119 || keycode == 115)
    {
        find_player_position(data->map, data->player);
        handle_keypress(keycode, data);
    }
    return 0;
}

void    init_graphics(t_map *map_design, t_hook_data *hook_data)
{
    t_map_objs  m_objs;
    t_char_info player;

    // Inicializar la minilibx
    m_objs.mlx = mlx_init();
    if (!m_objs.mlx)
        return ;
    set_window_size(&m_objs, map_design);
    // Crear una ventana
    m_objs.win = mlx_new_window(m_objs.mlx, m_objs.window_width, m_objs.window_height, "so_long");
    set_tile_size(&m_objs, map_design);
    open_images(&m_objs);
    hook_load(&player, map_design, &m_objs, hook_data);
    mlx_hook(m_objs.win, 17, 0L, exit_hook, NULL); // Manejar clic en la "X"
    mlx_hook(m_objs.win, 2, 1L << 0, key_hook, hook_data); // Manejar tecla presionada
    if (!m_objs.win)
    {
        mlx_destroy_display(m_objs.mlx);
        return ;
    }
    draw_level(&m_objs, map_design);
    // Mostrar la ventana
    mlx_loop(m_objs.mlx);
    // Limpiar y salir
    mlx_loop_end(m_objs.mlx);
    mlx_destroy_display(m_objs.mlx);
}
