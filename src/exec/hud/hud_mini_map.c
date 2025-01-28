/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_mini_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:04:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/28 07:35:38 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define BORDER 19

static short	render_tile(t_mlx *mlx, t_pos start, int color, size_t size)
{
	size_t	i;
	size_t	j;
	t_pos	pixel;

	i = BORDER;
	while (i < size + BORDER)
	{
		j = BORDER;
		while (j < size + BORDER)
		{
			pixel.x = start.x + j;
			pixel.y = start.y + i;
			if (pixel.x - BORDER >= MINIMAP_SIZE * MINIMAP_RADIUS || pixel.y
				- BORDER >= MINIMAP_SIZE * MINIMAP_RADIUS)
				return (0);
			ft_put_pixel_in_img(mlx, pixel, color);
			j++;
		}
		i++;
	}
	return (0);
}

static short	render_background_minimap(t_env *env)
{
	size_t	i;
	size_t	j;
	t_pos	start;

	i = BORDER;
	while (i < MINIMAP_RADIUS + BORDER)
	{
		j = BORDER;
		while (j < MINIMAP_RADIUS + BORDER)
		{
			start.x = i * MINIMAP_SIZE;
			start.y = j * MINIMAP_SIZE;
			render_tile(env->mlx, start, MINIMAP_COLOR_WALL, MINIMAP_SIZE);
			j++;
		}
		i++;
	}
	return (0);
}

static int	get_color_tile(t_map *map, t_pos map_pos)
{
	if (map_pos.y < map->height && map_pos.x < map->width
		&& map->grid[map_pos.y][map_pos.x])
	{
		if (map->grid[map_pos.y][map_pos.x] == '1')
			return (MINIMAP_COLOR_WALL);
		else if (map->grid[map_pos.y][map_pos.x] == CARAC_DOOR)
			return (MINIMAP_COLOR_DOOR);
		else if (map->grid[map_pos.y][map_pos.x] == CARAC_DOOR_OPEN)
			return (MINIMAP_COLOR_DOOR_OPEN);
		else if (ft_strchr(CARAC_PLAYER_VOID, map->grid[map_pos.y][map_pos.x]))
			return (MINIMAP_COLOR_VOID);
	}
	return (MINIMAP_COLOR_WALL);
}

static short	render_minimap(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;
	t_pos	map_pos;
	t_pos	start;

	i = 0;
	while (i < MINIMAP_RADIUS + 0)
	{
		j = 0;
		while (j < MINIMAP_RADIUS + 0)
		{
			start.y = i * MINIMAP_SIZE;
			start.x = j * MINIMAP_SIZE;
			map_pos.y = (floor)((map->player.pos.x + i) - MINIMAP_RADIUS / 2);
			map_pos.x = (floor)((map->player.pos.y + j) - MINIMAP_RADIUS / 2);
			render_tile(mlx, start, get_color_tile(map, map_pos), MINIMAP_SIZE);
			j++;
		}
		i++;
	}
	return (0);
}

short	handler_mini_map(t_env *env)
{
	t_pos	center;
	t_pos	pos_border;

	center.x = (MINIMAP_RADIUS * MINIMAP_SIZE / 2) - (MINIMAP_SIZE_PLAYER / 2);
	center.y = (MINIMAP_RADIUS * MINIMAP_SIZE / 2) - (MINIMAP_SIZE_PLAYER / 2);
	render_background_minimap(env);
	render_minimap(env->mlx, env->map);
	render_tile(env->mlx, center, MINIMAP_COLOR_PLAYER, MINIMAP_SIZE_PLAYER);
	pos_border.x = 10;
	pos_border.y = 10;
	helper_mlx_put_hud_to_win(env, env->textures->hud_border_map, pos_border);
	return (0);
}
