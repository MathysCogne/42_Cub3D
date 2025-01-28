/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:57:52 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/28 01:33:19 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_sprites_size(t_map *map, char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '2')
			map->sprites_size++;
		i++;
	}
}

static void	init_player_stats(t_map *map)
{
	map->player.bullets = START_BULLETS;
	map->player.pv = START_PV;
	map->player.stamina = START_STAMINA;
}

static short	find_player_pos(t_player *player, char *line, size_t y)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_strchr("NSEW", line[i]))
		{
			player->pos.x = y + 0.5;
			player->pos.y = i + 0.5;
			player->dir = line[i];
			if (player->dir == 'N')
				player->pos.angle_h = 90;
			else if (player->dir == 'S')
				player->pos.angle_h = 270;
			else if (player->dir == 'W')
				player->pos.angle_h = 180;
			else if (player->dir == 'E')
				player->pos.angle_h = 0;
			return (0);
		}
		i++;
	}
	return (0);
}

int	parse_map_line(char *line, t_env *env, t_map *map)
{
	map->grid = ft_realloc(map->grid, sizeof(char *) * (map->height),
			sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (1);
	map->grid[map->height] = ft_strdup(line);
	if (!map->grid[map->height])
		return (1);
	gc_add(env->gc, map->grid[map->height]);
	if (map->width < ft_strclen(line, '\n'))
		map->width = ft_strclen(line, '\n');
	find_player_pos(&map->player, line, map->height);
	init_player_stats(map);
	set_sprites_size(map, line);
	map->height++;
	return (0);
}
