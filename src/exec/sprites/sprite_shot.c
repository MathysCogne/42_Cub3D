/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_shot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:51:07 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/30 23:26:58 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	is_sprites_shot(t_map *map, t_textures *textures)
{
	t_pos		pos;
	t_sprite	*sprites;
	int			i;

	sprites = get_sprites(map, textures);
	if (sprites)
	{
		sort_sprites(sprites, map, is_superior);
		i = 0;
		while (i < map->sprites_size)
		{
			if (trigo_get_opposite_len(degree_to_radian(
						fabs(sprites[i].angle_diff)),
					sprites[i].distance) < 0.2 && sprites[i].distance < 10.0
				&& sprites[i].render == 1)
			{
				pos = sprites[i].pos;
				return (free(sprites), pos);
			}
			i++;
		}
		free(sprites);
	}
	return (pos.x = 0, pos.y = 0, pos);
}
