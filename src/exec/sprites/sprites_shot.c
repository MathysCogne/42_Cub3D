/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_shot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:51:07 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 06:35:23 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos is_sprites_shot(t_map *map, t_texture *texture)
{
	t_pos		pos;
	t_sprite	*sprites;
	int			i;

	sprites = get_sprites(map, texture);
	sort_sprites(sprites, map);
	i = 0;
	while (i < map->sprites_size)
	{
		if (trigo_opposite_side(sprites[i].angle_diff, sprites[i].distance) < 0.5)
			return (sprites[i].pos);
		i++;
	}
	free(sprites);
	pos.x = 0;
	pos.y = 0;
	return (pos);
}