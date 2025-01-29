/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:01:24 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 10:46:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	normalize_width(int img_width)
{
	return (RESH * img_width / 540);
}

int	normalize_height(int img_height)
{
	return (RESV * img_height / 360);
}

void	set_sprite(t_player *player, t_sprite *sprite, t_texture *texture)
{
	double	sprite_dx;
	double	sprite_dy;
	double	angle_diff;

	sprite_dy = sprite->pos.y + 0.5 - player->pos.y;
	sprite_dx = sprite->pos.x + 0.5 - player->pos.x;
	angle_diff = trigo_get_angle(sprite_dx, sprite_dy) / (M_PI / 180.0)
		- normalize_angle_h((player->pos.angle_h - 270));
	if (angle_diff > 180.0)
		angle_diff -= 360.0;
	if (angle_diff < -180.0)
		angle_diff += 360.0;
	if (fabs(angle_diff) > HFVH / 1.90)
		sprite->render = 0;
	else
	{
		sprite->render = 1;
		sprite->texture = texture;
		sprite->distance = trigo_get_hypotenuse_len(sprite_dy, sprite_dx);
		sprite->sprite_height = normalize_height(texture->height)
			/ sprite->distance;
		sprite->sprite_width = normalize_width(texture->width)
			/ sprite->distance;
		sprite->offsetx = (RESH / 2) - sprite->sprite_width / 2
			+ (tan(degree_to_radian(angle_diff))) * (RESH / 2);
		sprite->offsety = (RESV / 2) - sprite->sprite_height / 2
			- player->pos.angle_v * VERTICAL_FIX;
		sprite->angle_diff = angle_diff;
	}
}

t_texture	*get_texture(char c, t_textures *textures, t_map *map)
{
	if (c == '2')
		return (&textures->monster[get_id_monsters(map)]);
	if (c == '3')
		return (&textures->musk[get_id_musk(map)]);
	return (0);
}

t_sprite	*get_sprites(t_map *map, t_textures *textures)
{
	t_sprite	*sprites;
	size_t		y;
	size_t		x;
	size_t		k;

	sprites = malloc(sizeof(t_sprite) * map->sprites_size);
	if (!sprites)
		return (0);
	k = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '2' || map->grid[y][x] == '3')
			{
				sprites[k].pos.x = x;
				sprites[k].pos.y = y;
				set_sprite(&map->player, &sprites[k],
					get_texture(map->grid[y][x], textures, map));
				k++;
			}
			x++;
		}
		y++;
	}
	return (sprites);
}
