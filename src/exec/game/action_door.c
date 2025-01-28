/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:58:22 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/28 07:37:03 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	handler_door(t_env *env)
{
	t_map	*map;

	map = env->map;
	if (player_adjacent_close_door(map->grid, (int)map->player.pos.y,
			(int)map->player.pos.x))
		ft_printf(MINT_GREEN NAME "Open Sesame !..\n");
	else if (player_adjacent_open_door(map->grid, (int)map->player.pos.y,
			(int)map->player.pos.x))
		ft_printf(MINT_GREEN NAME "Close Sesame !..\n");
	return (0);
}
