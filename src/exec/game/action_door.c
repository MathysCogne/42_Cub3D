/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:58:22 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 20:53:42 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
