/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_close_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:30:26 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/31 09:54:54 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	is_not_wall_adjacent(char **grid, size_t y, size_t x)
{
	size_t	len;

	if (!grid || !grid[y] || y == 0)
		return (1);
	len = ft_strlen(grid[y]);
	if (x >= len)
		return (1);
	if (!grid[y - 1] || !grid[y + 1])
		return (1);
	if (x == 0 || x >= ft_strlen(grid[y - 1]) || x >= ft_strlen(grid[y + 1]))
		return (1);
	if (grid[y - 1][x] == CARAC_VOID || grid[y + 1][x] == CARAC_VOID)
		return (1);
	if (grid[y][x - 1] == CARAC_VOID || (x + 1 < len && grid[y][x
			+ 1] == CARAC_VOID))
		return (1);
	return (0);
}

static short	is_empty_line(char **grid, size_t y)
{
	size_t	x;

	x = 0;
	if (!grid[y][x])
		return (0);
	while (grid[y][x])
	{
		if (ft_strchr(CARAC_MAP_NO_SPACE, grid[y][x]))
			return (0);
		x++;
	}
	return (1);
}

short	valid_close_wall(t_map *map, char **grid)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (y < map->height)
	{
		if (is_empty_line(grid, y))
			return (1);
		x = 0;
		while (grid[y][x])
		{
			if (ft_strchr(CARAC_PLAYER_VOID, grid[y][x]) && (x == 0 || y == 0
					|| y == map->height - 1))
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
