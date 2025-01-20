/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:31:48 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/20 20:32:06 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	valid_player(t_map *map, char **grid)
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
