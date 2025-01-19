/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:05:40 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/19 23:29:13 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	draw_tile_2d(t_mlx *mlx, t_pos start, int color)
{
	t_pos	pos;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < RENDER_SIZE)
	{
		j = 0;
		while (j < RENDER_SIZE)
		{
			pos.x = start.x + j;
			pos.y = start.y + i;
			ft_put_pixel_in_img(mlx, pos, color);
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
			tile_pos.x = map_pos.x * RENDER_SIZE;
			tile_pos.y = map_pos.y * RENDER_SIZE;
			if (map->grid[map_pos.y][map_pos.x] == '1')
				draw_tile_2d(mlx, tile_pos, 0x00FF00);
			else if (map->grid[map_pos.y][map_pos.x] == '0')
				draw_tile_2d(mlx, tile_pos, 0x0000FF);
			else if (map_pos.x == map->player.pos.x
				&& map_pos.y == map->player.pos.y)
				draw_tile_2d(mlx, tile_pos, 0x0000F0);
			map_pos.x++;
		}
		map_pos.y++;
	}
	if (!mlx_put_image_to_window(mlx->id, mlx->win, mlx->render_pixel, 0, 0))
		return (1);
	return (0);
}
