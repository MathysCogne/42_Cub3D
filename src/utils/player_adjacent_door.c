/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_adjacent_door.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:53:24 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 20:53:59 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	player_adjacent_open_door(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (0);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (0);
	if (grid[y - 1][x] == '8')
		return (grid[y - 1][x] = '9', 1);
	else if (grid[y + 1][x] == '8')
		return (grid[y + 1][x] = '9', 1);
	else if (grid[y][x + 1] == '8')
		return (grid[y][x + 1] = '9', 1);
	else if (grid[y][x - 1] == '8')
		return (grid[y][x - 1] = '9', 1);
	return (0);
}

short	player_adjacent_close_door(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (0);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (0);
	if (grid[y - 1][x] == '9')
		return (grid[y - 1][x] = '8', 1);
	else if (grid[y + 1][x] == '9')
		return (grid[y + 1][x] = '8', 1);
	else if (grid[y][x + 1] == '9')
		return (grid[y][x + 1] = '8', 1);
	else if (grid[y][x - 1] == '9')
		return (grid[y][x - 1] = '8', 1);
	return (0);
}

short	player_adjacent_door(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (0);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (0);
	if (grid[y - 1][x] == '8' || grid[y + 1][x] == '8' || grid[y][x + 1] == '8'
		|| grid[y][x - 1] == '8')
		return (8);
	if (grid[y - 1][x] == '9' || grid[y + 1][x] == '9' || grid[y][x + 1] == '9'
		|| grid[y][x - 1] == '9')
		return (9);
	return (0);
}