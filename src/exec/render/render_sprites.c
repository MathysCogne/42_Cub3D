/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:32:31 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/30 21:08:57 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sprite_pixel(t_mlx *mlx, t_sprite *sprite, int x, int y)
{
	t_pos	pos;
	int		color;
	double	ratio_h;
	double	ratio_w;

	ratio_h = (double)sprite->texture->height / sprite->sprite_height;
	ratio_w = (double)sprite->texture->width / sprite->sprite_width;
	color = ft_get_pixel_color(sprite->texture,
			x * ratio_w / sprite->texture->width,
			y * ratio_h / sprite->texture->height);
	if (color != (int)0xff000000)
	{
		pos.y = (sprite->offsety + y) * 2;
		pos.x = (sprite->offsetx + x) * 2;
		ft_put_pixel_in_img(mlx, pos, color);
	}
}

void	handle_draw_sprite(t_mlx *mlx, t_sprite *sprite, t_render **render)
{
	int		x;
	int		y;

	y = 0;
	while (y < sprite->sprite_height)
	{
		x = 0;
		while (x < sprite->sprite_width)
		{
			if (sprite->distance > 0.5
				&& sprite->offsety + y < RESH
				&& sprite->offsety + y >= 0
				&& sprite->offsetx + x >= 0
				&& sprite->offsetx + x < RESH
				&& (sprite->offsety + y) * RESH + (sprite->offsetx + x)
				< RESH * RESV
				&& sprite->distance
				< render[(sprite->offsety + y) * RESH
					+ (sprite->offsetx + x)]->distance)
				put_sprite_pixel(mlx, sprite, x, y);
			x++;
		}
		y++;
	}
}

int	render_sprites(t_map *map, t_render **render,
					t_mlx *mlx, t_textures *textures)
{
	t_sprite	*sprites;
	int			i;

	sprites = get_sprites(map, textures);
	if (!sprites)
		return (0);
	sort_sprites(sprites, map, is_inferior);
	i = 0;
	while (i < map->sprites_size)
	{
		if (sprites[i].render)
		{
			handle_draw_sprite(mlx, &sprites[i], render);
		}
		i++;
	}
	free(sprites);
	return (1);
}
