/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:13:35 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/29 06:35:49 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// INSERT ICI FT QUI RENVOIE 1 (ID DU MOB) SI LE TIR A TOUCHE ENNEMY
// POUR QUE JE METTE A JOUR LE MOB MORT

static short	piou_piou(t_env *env, t_map *map)
{
	t_pos	pos;

	if (map->player.bullets > 0)
	{
		pos = is_sprites_shot(map, env->textures->monster);
		if (pos.x != 0 && pos.y != 0)
		{
			map->grid[pos.y][pos.x] = '4';
			map->sprites_size--;
		}
		map->player.bullets--;
	}
	else
		ft_printf(MINT_GREEN NAME "No bullet in your weapon !\n");
	return (0);
}

short	handler_action_weapon(t_env *env)
{
	if (env->event->click_left)
		piou_piou(env, env->map);
	return (0);
}
