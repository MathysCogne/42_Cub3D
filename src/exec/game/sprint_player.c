/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:05:59 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:02:07 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	regen_stamina(t_env *env)
{
	if (!env->event->move_sprint && env->map->player.stamina < START_STAMINA)
		env->map->player.stamina += REGEN_STAMINA;
}

short	action_sprint(t_map *map, double x, double y)
{
	double	new_x;
	double	new_y;
	double	spent;

	if (map->player.stamina <= SPRINT_MIN_COST)
		return (1);
	new_x = map->player.pos.y + x * SPRINT_SPEED;
	new_y = map->player.pos.x + y * SPRINT_SPEED;
	spent = sqrt(pow(new_x - map->player.pos.y, 2) + pow(new_y
				- map->player.pos.x, 2));
	if (spent > map->player.stamina)
		return (1);
	map->player.stamina -= spent;
	return (0);
}
