/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:58:22 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 18:28:00 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	player_adjacent_open_door(char **grid, size_t y, size_t x)
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

static short	player_adjacent_close_door(char **grid, size_t y, size_t x)
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

short	handler_door(t_env *env)
{
	t_map	*map;

	map = env->map;
	if (player_adjacent_close_door(map->grid, (int)map->player.pos.x,
			(int)map->player.pos.y))
		ft_printf(MINT_GREEN NAME "Open Sesame !..\n");
	else if (player_adjacent_open_door(map->grid, (int)map->player.pos.x,
			(int)map->player.pos.y))
		ft_printf(MINT_GREEN NAME "Close Sesame !..\n");
	return (0);
}
