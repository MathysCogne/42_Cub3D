/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_hands_fights.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:08:11 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:38 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	player_adjacent_ennemy(char **grid, size_t y, size_t x)
{
	if (!grid[y + 1][x] || !grid[y - 1][x])
		return (0);
	else if (!grid[y][x + 1] || !grid[y][x - 1])
		return (0);
	if (ft_strchr(CARAC_ENNEMY, grid[y - 1][x]))
		return (grid[y - 1][x] = CARAC_BOT_BLOOD, 1);
	else if (ft_strchr(CARAC_ENNEMY, grid[y + 1][x]))
		return (grid[y + 1][x] = CARAC_BOT_BLOOD, 1);
	else if (ft_strchr(CARAC_ENNEMY, grid[y][x + 1]))
		return (grid[y][x + 1] = CARAC_BOT_BLOOD, 1);
	else if (ft_strchr(CARAC_ENNEMY, grid[y][x - 1]))
		return (grid[y][x - 1] = CARAC_BOT_BLOOD, 1);
	return (0);
}

void	handler_action_hands_fights(t_env *env)
{
	if (player_adjacent_ennemy(env->map->grid, env->map->player.pos.y,
			env->map->player.pos.x))
	{
		ft_printf(RED NAME "Hand-to-hand combat with an enemy !..\n");
		ft_printf(RED NAME "You lose two PV\n");
		env->map->player.pv -= 2;
		env->map->sprites_size--;
		hud_bam_comics(env, 1);
	}
}
