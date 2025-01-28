/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:01:24 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/28 07:35:38 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_sprite_distance(double sprite_dy, double sprite_dx)
{
	return (sqrt(sprite_dx * sprite_dx + sprite_dy * sprite_dy));
}

double	get_sprite_angle(double sprite_dy, double sprite_dx)
{
	return atan2(sprite_dy, sprite_dx);
}

void	set_sprite(t_player *player, t_sprite *sprite, t_texture *texture)
{
	double sprite_dx;
	double sprite_dy;
	
	sprite_dy = sprite->pos.y + 0.5 - player->pos.y;
	sprite_dx = sprite->pos.x + 0.5 - player->pos.x;
	double angle_diff = get_sprite_angle(sprite_dy, sprite_dx) / (M_PI / 180.0) - normalize_angle_h((player->pos.angle_h - 270));
	if (angle_diff > 180.0)
		angle_diff -= 360.0;
	if (angle_diff < -180.0)
		angle_diff += 360.0;
	if (fabs(angle_diff) > HFVH / 2)
		sprite->render = 0;
	else
	{
		sprite->render = 1;
		sprite->sprite_height = texture->height / sprite->distance;
		sprite->sprite_width = texture->width / sprite->distance;
		sprite->distance = get_sprite_distance(sprite_dy, sprite_dx);
		sprite->offsetx = (RESH / 2) - sprite->sprite_width / 2 + (tan(degree_to_radian(angle_diff))) * (RESH / 2);
		sprite->offsety = (RESV / 2) - sprite->sprite_height / 2 - ((RESH / 2) / (sprite->distance + 1));
	}
}

t_sprite	*get_sprites(t_map *map, t_texture *texture)
{
	t_sprite	*sprites;
	size_t		x;
	size_t		y;
	size_t		k;

	sprites = malloc(sizeof(t_sprite) * map->sprites_size);
	if (!sprites)
		return (0);
	k = 0;
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->grid[x][y] == '2')
			{
				sprites[k].pos.x = x;
				sprites[k].pos.y = y;
				set_sprite(&map->player, &sprites[k], texture);
				k++;
			}
			y++;
		}
		x++;
	}
	return (sprites);
}