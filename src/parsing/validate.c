/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:44:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/20 00:04:59 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	valid_player(t_map *map, char **grid)
{
	size_t	count_player;
	size_t	y;
	size_t	x;

	y = 1;
	count_player = 0;
	while (y < map->height)
	{
		x = 0;
		while (grid[y][x])
		{
			if (ft_strchr(CARAC_PLAYER, grid[y][x]))
				count_player++;
			x++;
		}
		y++;
	}
	if (count_player != 1)
		return (1);
	return (0);
}

static short	is_not_wall_adjacent(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (1);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (1);
	if (grid[y + 1][x] == ' ' || grid[y - 1][x] == ' ')
		return (1);
	else if (grid[y][x + 1] == ' ' || grid[y][x - 1] == ' ')
		return (1);
	return (0);
}

short	valid_close_wall(t_map *map, char **grid)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (y < map->height)
	{
		x = 0;
		while (grid[y][x])
		{
			if (ft_strchr(CARAC_PLAYER_VOID, grid[y][x]) && (x == 0 || y == 0
					|| x == map->width - 1 || y == map->height - 1))
				return (1);
			if (ft_strchr(CARAC_PLAYER_VOID, grid[y][x])
				&& is_not_wall_adjacent(grid, y, x))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static short	valid_carac(t_map *map)
{
	size_t	i;
	short	is_data_part;

	i = 0;
	is_data_part = 1;
	while (map->file[i])
	{
		if (is_texture_line(&map->file[i]) && is_data_part)
		{
			while (map->file[i] && map->file[i] != '\n')
				i++;
		}
		else if (!is_texture_line(&map->file[i]) && map->file[i] != '\n')
			is_data_part = 0;
		if (!ft_strchr(CARAC_MAP, map->file[i]) && map->file[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

short	handler_validate_parsing(t_env *env, t_map *map)
{
	(void)env;
	if (valid_carac(map))
		return (env->err = ERR_PARSE_CARAC, 1);
	if (valid_close_wall(map, map->grid))
		return (env->err = ERR_PARSE_WALL, 1);
	if (valid_player(map, map->grid))
		return (env->err = ERR_PARSE_PLAYER, 1);
	// if (valid_data(map))
	// 	return (1);
	return (0);
}