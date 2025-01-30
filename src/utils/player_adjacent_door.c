/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_adjacent_door.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:53:24 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 23:05:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	player_adjacent_open_door(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (0);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (0);
	if (grid[y - 1][x] == CARAC_DOOR_OPEN)
		return (grid[y - 1][x] = CARAC_DOOR, 1);
	else if (grid[y + 1][x] == CARAC_DOOR_OPEN)
		return (grid[y + 1][x] = CARAC_DOOR, 1);
	else if (grid[y][x + 1] == CARAC_DOOR_OPEN)
		return (grid[y][x + 1] = CARAC_DOOR, 1);
	else if (grid[y][x - 1] == CARAC_DOOR_OPEN)
		return (grid[y][x - 1] = CARAC_DOOR, 1);
	return (0);
}

short	player_adjacent_close_door(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (0);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (0);
	if (grid[y - 1][x] == CARAC_DOOR)
		return (grid[y - 1][x] = CARAC_DOOR_OPEN, 1);
	else if (grid[y + 1][x] == CARAC_DOOR)
		return (grid[y + 1][x] = CARAC_DOOR_OPEN, 1);
	else if (grid[y][x + 1] == CARAC_DOOR)
		return (grid[y][x + 1] = CARAC_DOOR_OPEN, 1);
	else if (grid[y][x - 1] == CARAC_DOOR)
		return (grid[y][x - 1] = CARAC_DOOR_OPEN, 1);
	return (0);
}

short	player_adjacent_door(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (0);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (0);
	if (grid[y - 1][x] == CARAC_DOOR_OPEN || grid[y + 1][x] == CARAC_DOOR_OPEN
		|| grid[y][x + 1] == CARAC_DOOR_OPEN || grid[y][x
		- 1] == CARAC_DOOR_OPEN)
		return (8);
	if (grid[y - 1][x] == CARAC_DOOR || grid[y + 1][x] == CARAC_DOOR
		|| grid[y][x + 1] == CARAC_DOOR || grid[y][x - 1] == CARAC_DOOR)
		return (9);
	return (0);
}
