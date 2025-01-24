/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:04:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 21:30:20 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	draw_tile_2d(t_map *map, t_mlx *mlx, t_pos start)
{
	t_pos	pos;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < MINIMAP_SIZE)
	{
		j = 0;
		while (j < MINIMAP_SIZE)
		{
			pos.x = start.x + j;
			pos.y = start.y + i;
			if (map->grid[start.y][start.x] == '1')
				ft_put_pixel_in_img(mlx, pos, MINIMAP_COLOR_WALL);
			else if (map->grid[start.y][start.x] == '0')
				ft_put_pixel_in_img(mlx, pos, MINIMAP_COLOR_VOID);
			else if (ft_strchr(CARAC_PLAYER, map->grid[start.y][start.x]))
				ft_put_pixel_in_img(mlx, pos, MINIMAP_COLOR_SPAWN);
			j++;
		}
		i++;
	}
	return (0);
}

short	render_map_2d(t_map *map, t_mlx *mlx)
{
	t_pos	tile_pos;
	t_pos	map_pos;

	map_pos.y = 0;
	while (map_pos.y < map->height)
	{
		map_pos.x = 0;
		while (map->grid[map_pos.y][map_pos.x])
		{
			tile_pos.x = map_pos.x * MINIMAP_SIZE;
			tile_pos.y = map_pos.y * MINIMAP_SIZE;
			draw_tile_2d(map, mlx, tile_pos);
			map_pos.x++;
		}
		map_pos.y++;
	}
	return (0);
}

short	handler_mini_map(t_env *env)
{
	render_map_2d(env->map, env->mlx);
	return (0);
}