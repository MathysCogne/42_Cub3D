/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:01:24 by achaisne          #+#    #+#             */
/*   Updated: 2025/02/02 09:15:04 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite(t_sprite *sprite, t_map *map, double angle_diff,
		t_textures *textures)
{
	double	sprite_dx;
	double	sprite_dy;

	sprite_dy = sprite->pos.y + 0.5 - map->player.pos.y;
	sprite_dx = sprite->pos.x + 0.5 - map->player.pos.x;
	sprite->render = 1;
	sprite->distance = trigo_get_hypotenuse_len(sprite_dy, sprite_dx);
	sprite->texture = get_texture(map->grid[sprite->pos.y][sprite->pos.x],
			textures, map);
	sprite->sprite_height = normalize_height(sprite->texture->height)
		/ sprite->distance;
	sprite->sprite_width = normalize_width(sprite->texture->width)
		/ sprite->distance;
	sprite->offsetx = (RESH / 2) - sprite->sprite_width / 2
		+ (tan(degree_to_radian(angle_diff))) * (RESH / 2);
	sprite->offsety = (RESV / 2) - sprite->sprite_height / 2
		- map->player.pos.angle_v * VERTICAL_FIX;
	sprite->angle_diff = angle_diff;
}

void	try_set_sprite(t_pos *pos, t_sprite *sprite, t_textures *textures,
		t_map *map)
{
	double	sprite_dx;
	double	sprite_dy;
	double	angle_diff;

	sprite->pos.x = pos->x;
	sprite->pos.y = pos->y;
	sprite_dy = sprite->pos.y + 0.5 - map->player.pos.y;
	sprite_dx = sprite->pos.x + 0.5 - map->player.pos.x;
	angle_diff = trigo_get_angle(sprite_dx, sprite_dy) / (M_PI / 180.0)
		- normalize_angle_h((map->player.pos.angle_h - 270));
	if (angle_diff > 180.0)
		angle_diff -= 360.0;
	if (angle_diff < -180.0)
		angle_diff += 360.0;
	if (fabs(angle_diff) > FOVH / 1.90)
		sprite->render = 0;
	else
		set_sprite(sprite, map, angle_diff, textures);
}

t_sprite	*get_sprites(t_map *map, t_textures *textures)
{
	t_sprite	*sprites;
	t_pos		pos;
	size_t		k;

	sprites = ft_calloc(sizeof(t_sprite), map->sprites_size);
	if (!sprites)
		return (0);
	k = 0;
	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (map->grid[pos.y][pos.x])
		{
			if (map->grid[pos.y][pos.x] == CARAC_MONSTER
				|| map->grid[pos.y][pos.x] == CARAC_MUSK)
			{
				try_set_sprite(&pos, &sprites[k], textures, map);
				k++;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (sprites);
}
