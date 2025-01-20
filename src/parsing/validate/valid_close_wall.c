/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_close_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:30:26 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/20 20:31:17 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
