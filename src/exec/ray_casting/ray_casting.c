/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:05:18 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/17 20:53:35 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cub3d.h"

// view of 360 to start
int	get_vue_data(t_env env)
{
	int		x;
	int		y;

	x = 0;
	while (env.map->grid[x])
	{
		y = 0;
		while (env.map->grid[y])
		{
			if (x <= env.map->player.pos.x && y <= env.map->player.pos.y)
				env.map->grid[x][y].distance = sqrt(pow(env.map->player.pos.x - x, 2) + pow(env.map->player.pos.y - y, 2));
			else if (x >= env.map->player.pos.x && y <= env.map->player.pos.y)
				env.map->grid[x][y].distance = sqrt(pow(x - env.map->player.pos.x, 2) + pow(env.map->player.pos.y - y, 2));
			else if (x <= env.map->player.pos.x && y >= env.map->player.pos.y)
				env.map->grid[x][y].distance = sqrt(pow(env.map->player.pos.x - x, 2) + pow(y - env.map->player.pos.y, 2));
			else if (x >= env.map->player.pos.x && y >= env.map->player.pos.y)
				env.map->grid[x][y].distance = sqrt(pow(x - env.map->player.pos.x, 2) + pow(y - env.map->player.pos.y, 2));
			env.map->grid[x][y].angle = atan2(x - env.map->player.pos.x, env.map->player.pos.y - y) * (180.0 / M_PI);
			y++;
		}
		x++;
	}
	debug(env);
}

void	debug(t_env env)
{
	int		x;
	int		y;

	x = 0;
	while (env.map->grid[x])
	{
		y = 0;
		while (env.map->grid[y])
		{
			printf("%c", env.map->grid[x][y].value);
			printf("%d", env.map->grid[x][y].distance);
			printf("%d", env.map->grid[x][y].value);
			y++;
		}
			printf("%c", env.map->grid[x][y].value);
		x++;
	}
}

/*
TEST MAP
1111111
1001001
1102011
1001001
1111111
*/