/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:37:08 by achaisne          #+#    #+#             */
/*   Updated: 2025/02/02 08:47:52 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_sprite *sprites, t_map *map, int (*compare)(int, int))
{
	int			i;
	t_sprite	buffer;
	int			trigger;

	trigger = 0;
	while (!trigger)
	{
		i = 0;
		trigger = 1;
		while (i < map->sprites_size - 1)
		{
			if (compare(sprites[i].distance, sprites[i + 1].distance))
			{
				buffer = sprites[i];
				sprites[i] = sprites[i + 1];
				sprites[i + 1] = buffer;
				trigger = 0;
			}
			i++;
		}
	}
}
