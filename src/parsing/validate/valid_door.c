/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:34:30 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 23:07:50 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	check_adjacent_door(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (1);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (1);
	if (grid[y + 1][x] != CARAC_WALL && grid[y - 1][x] != CARAC_WALL)
	{
		if (grid[y][x + 1] != CARAC_WALL && grid[y][x - 1] != CARAC_WALL)
			return (1);
	}
	else if (grid[y][x + 1] != CARAC_WALL && grid[y][x - 1] != CARAC_WALL)
	{
		if (grid[y + 1][x] != CARAC_WALL && grid[y - 1][x] != CARAC_WALL)
			return (1);
	}
	return (0);
}

short	valid_door(t_map *map, char **grid)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (y < map->height)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == CARAC_DOOR && check_adjacent_door(grid, y, x))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
