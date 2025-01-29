/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:32:31 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 08:45:14 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_mlx *mlx, t_sprite *sprite, t_render **render)
{
	t_pos	pos;
	double	i;
	double	j;
	int		x;
	int		y;
	int		color;
	double	ratio_h;
	double	ratio_w;

	(void)render;
	ratio_h = (double)sprite->texture->height / sprite->sprite_height;
	ratio_w = (double)sprite->texture->width / sprite->sprite_width;
	y = 0;
	i = 0;
	while (y < sprite->sprite_height)
	{
		x = 0;
		j = 0;
		while (x < sprite->sprite_width)
		{
			color = ft_get_pixel_color(sprite->texture, j / sprite->texture->width, i
					/ sprite->texture->height);
			if (color != (int)0xff000000 && sprite->distance > 0.5
				&& (sprite->offsety + y) >= 0 && (sprite->offsety + y) < RESV
				&& (sprite->offsetx + x) >= 0 && (sprite->offsetx + x) < RESH
				&& (sprite->offsety + y) * RESH + (sprite->offsetx + x) < RESH
				* RESV && sprite->distance < render[(sprite->offsety + y)
				* RESH + (sprite->offsetx + x)]->distance)
			{
				pos.y = (sprite->offsety + y) * 2;
				pos.x = (sprite->offsetx + x) * 2;
				ft_put_pixel_in_img(mlx, pos, color);
			}
			j += ratio_w;
			x++;
		}
		i += ratio_h;
		y++;
	}
}

int	render_sprites(t_map *map, t_render **render, t_mlx *mlx, t_textures *textures)
{
	t_sprite	*sprites;
	int			i;

	sprites = get_sprites(map, textures);
	sort_sprites(sprites, map, is_inferior);
	if (!sprites)
		return (0);
	i = 0;
	while (i < map->sprites_size)
	{
		if (sprites[i].render)
		{
			draw_sprite(mlx, &sprites[i], render);
		}
		i++;
	}
	free(sprites);
	return (1);
}
