/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:32:31 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/28 21:18:12 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_mlx *mlx, t_sprite *sprites, t_texture *texture, t_render **render)
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
	ratio_h = (double)texture->height / sprites->sprite_height;
	ratio_w = (double)texture->width / sprites->sprite_width;
	y = 0;
	i = 0;
	while (y < sprites->sprite_height)
	{
		x = 0;
		j = 0;
		while (x < sprites->sprite_width)
		{
			color = ft_get_pixel_color(texture, j / texture->width, i
					/ texture->height);
			if (color != (int)0xff000000
				&& sprites->distance > 0.5
				&& (sprites->offsety + y) >= 0
				&& (sprites->offsety + y) < RESV
				&& (sprites->offsetx + x) >= 0
				&& (sprites->offsetx + x) < RESH
				&& (sprites->offsety + y) * RESH + (sprites->offsetx + x) < RESH * RESV
				&& sprites->distance < render[(sprites->offsety + y) * RESH + (sprites->offsetx + x)]->distance)
			{
				pos.y = (sprites->offsety + y) * 2;
				pos.x = (sprites->offsetx + x) * 2;
				ft_put_pixel_in_img(mlx, pos, color);
			}
			j += ratio_w;
			x++;
		}
		i += ratio_h;
		y++;
	}
}

int	render_sprites(t_map *map, t_render **render, t_mlx *mlx, t_textures *texture)
{
	t_sprite *sprites;
	int i;

	(void)render;
	sprites = get_sprites(map, &texture->sprite);
	sort_sprites(sprites, map);
	if (!sprites)
		return (0);
	i = 0;
	while (i < map->sprites_size)
	{
		if (sprites[i].render)
		{
			if (sprites[i].value == '2')
				draw_sprite(mlx, &sprites[i], &texture->sprite, render);
			else if (sprites[i].value == '3')
				draw_sprite(mlx, &sprites[i], &texture->musk, render);
		}
		i++;
	}
	free(sprites);
	return (1);
}