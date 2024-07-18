#include "../includes/map.h"

void	sl_put_player(t_map *map)
{
	int	height;
	int	width;

	height = -1;
	while (++height < map->rows)
	{
		width = -1;
		while (map->grid[height][++width])
		{
			if (map->grid[height][width] == 'P')
			{
				map->player_x = width;
				map->player_y = height;
				return ;
			}
		}
	}
}

static char	**sl_copy_map(t_map *map)
{
	char	**copy_map;
	int		i;

	copy_map = (char **)malloc(sizeof(char *) * (map->rows));
	if (!copy_map)
	{
		ft_putstr_fd("Malloc error..!", 2);
		return (NULL);
	}
	i = 0;
	while (i < map->rows)
	{
		copy_map[i] = ft_strdup(map->grid[i]);
		if (!copy_map[i])
		{
			ft_putstr_fd("Malloc error..!", 2);
			return (NULL);
		}
		if (copy_map[i] == NULL)
			break ;
		i++;
	}
	return (copy_map);
}

static void	sl_path_find(char **copy_map, int *collect_count, int y, int x)
{
	if (copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
		(*collect_count)++;
	if (copy_map[y][x] == 'E')
		copy_map[y][x] = '1';
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'E')
		return ;
	copy_map[y][x] = '1';
	sl_path_find(copy_map, collect_count, y + 1, x);
	sl_path_find(copy_map, collect_count, y - 1, x);
	sl_path_find(copy_map, collect_count, y, x + 1);
	sl_path_find(copy_map, collect_count, y, x - 1);
}

static void	sl_copy_map_free(char **copy_map, t_map *t_map_info)
{
	int	i;

	i = 0;
	while (i < t_map_info->rows)
	{
		free(copy_map[i]);
		i++;
	}
	free(copy_map);
}

void	sl_path_check(t_map *t_map_info, int y, int x)
{
	char	**copy_map;
	int		collectibles;

	collectibles = 0;
	copy_map = sl_copy_map(t_map_info);
	if (!copy_map)
		return ;
	sl_path_find(copy_map, &collectibles, y, x);
	if (collectibles != t_map_info->coin_num + 1)
	{
		sl_copy_map_free(copy_map, t_map_info);
		ft_putstr_fd("Wrong Map...! Maybe the character is in a box\n", 2);
		exit(1);
	}
	sl_copy_map_free(copy_map, t_map_info);
}
