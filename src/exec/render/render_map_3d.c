/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:31:51 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 22:55:47 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_pixel_rgb_or_texture(t_render *render, t_textures *textures)
{
	if (render->texture == &textures->top)
	{
		if (textures->rgb_ceiling[0] == -1 && textures->top.value)
			return (ft_get_pixel_color(&textures->top, render->offset_x,
					render->offset_y));
		else
			return (rgb_to_hex(textures->rgb_floor));
	}
	if (render->texture == &textures->bot)
	{
		if (textures->rgb_floor[0] == -1 && textures->bot.value)
			return (ft_get_pixel_color(&textures->bot, render->offset_x,
					render->offset_y));
		else
			return (rgb_to_hex(textures->rgb_ceiling));
	}
	else
		return (0);
}

static void	set_pixel(t_mlx *mlx, t_render *render, t_pos pos,
		t_textures *textures)
{
	int	color;

	if (render->texture == &textures->top || render->texture == &textures->bot)
		color = set_pixel_rgb_or_texture(render, textures);
	else
		color = ft_get_pixel_color(render->texture, render->offset_x,
				render->offset_y);
	pos.x *= 2;
	pos.y *= 2;
	ft_put_pixel_in_img(mlx, pos, color);
}

short	render_map_3d(t_map *map, t_mlx *mlx, t_textures *textures)
{
	t_pos		pos;
	t_render	**render;

	render = ray_cast(&map->player, map->grid, textures);
	if (!render)
		return (1);
	pos.y = 0;
	while (pos.y < RESV)
	{
		pos.x = 0;
		while (pos.x < RESH)
		{
			set_pixel(mlx, render[(RESH * pos.y) + pos.x], pos, textures);
			pos.x++;
		}
		pos.y++;
	}
	if (map->sprites_size > 0 && !render_sprites(map, render, mlx, textures))
		return (detroy_render(render), 1);
	bi_interpolation_decompression(mlx);
	detroy_render(render);
	return (0);
}
