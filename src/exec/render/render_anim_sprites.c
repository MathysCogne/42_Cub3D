/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_anim_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:34:34 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/29 16:18:15 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	get_id_monsters(t_map *map)
{
	static short	id = 0;
	static int		count_call = 0;

	if (id >= FRAME_MAX_MONSTERS -1 && count_call == map->sprites_size)
		id = 0;
	if (count_call >= map->sprites_size * 4)
	{
		id++;
		count_call = 0;
	}
	if (id >= FRAME_MAX_MONSTERS - 1)
		id = 0;
	count_call++;
	return (id);
}

short	get_id_musk(t_map *map)
{
	static short	id = 0;
	static int		count_call = 0;

	if (id >= FRAME_MAX_MUSK - 1 && count_call == map->sprites_size)
		id = 0;
	if (count_call >= map->sprites_size)
	{
		id++;
		count_call = 0;
	}
	if (id >= FRAME_MAX_MUSK - 1)
		id = 0;
	count_call++;
	return (id);
}
