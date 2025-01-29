/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:31:51 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 06:01:46 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_pixel_rgb_or_texture(t_render *render, t_textures *texture)
{
	if (render->pole == TOP)
	{
		if (texture->rgb_ceiling[0] == -1 && texture->top.value)
			return (ft_get_pixel_color(&texture->top, render->offset_x,
					render->offset_y));
		else
			return (rgb_to_hex(texture->rgb_floor));
	}
	if (render->pole == BOT)
	{
		if (texture->rgb_floor[0] == -1 && texture->bot.value)
			return (ft_get_pixel_color(&texture->bot, render->offset_x,
					render->offset_y));
		else
			return (rgb_to_hex(texture->rgb_ceiling));
	}
	else
		return (0);
}

static void	set_pixel(t_mlx *mlx, t_render *render, int x, int y,
		t_textures *texture)
{
	t_pos	pos;
	int		color;

	if (render->pole == NO)
		color = ft_get_pixel_color(&texture->no, render->offset_x,
				render->offset_y);
	if (render->pole == SO)
		color = ft_get_pixel_color(&texture->so, render->offset_x,
				render->offset_y);
	if (render->pole == EA)
		color = ft_get_pixel_color(&texture->ea, render->offset_x,
				render->offset_y);
	if (render->pole == WE)
		color = ft_get_pixel_color(&texture->we, render->offset_x,
				render->offset_y);
	if (render->pole == TOP || render->pole == BOT)
		color = set_pixel_rgb_or_texture(render, texture);
	if (render->pole == DOOR_EA || render->pole == DOOR_WE
		|| render->pole == DOOR_SN)
		color = ft_get_pixel_color(&texture->door, render->offset_x,
				render->offset_y);
	if (render->pole == BOT_BLOOD)
		color = ft_get_pixel_color(&texture->bot_blood, render->offset_x,
				render->offset_y);
	pos.x = x;
	pos.y = y;
	ft_put_pixel_in_img(mlx, pos, color);
}

short	render_map_3d(t_map *map, t_mlx *mlx, t_textures *texture)
{
	int x;
	int y;

	t_render **render = ray_cast(&map->player, map->grid);
	if (!render)
		return (1);
	y = 0;
	while (y < RESV)
	{
		x = 0;
		while (x < RESH)
		{
			set_pixel(mlx, render[(RESH * y) + x], x * 2, y * 2, texture);
			x++;
		}
		y++;
	}
	if (map->sprites_size > 0 && !render_sprites(map, render, mlx, texture))
		return (detroy_render(render), 1);
	bi_interpolation_decompression(mlx);
	detroy_render(render);
	return (0);
}