/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_shot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:51:07 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/28 14:57:04 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_sprites_shot(t_map *map, t_texture *texture)
{
	t_sprite	*sprites;
	int			i;

	sprites = get_sprites(map, texture);
	sort_sprites(sprites, map);
	i = 0;
	while (i < map->sprites_size)
	{
		if (sprites[i].angle_diff < 10 && sprites[i].distance < 10)
			return (1);
		i++;
	}
	return (0);
}