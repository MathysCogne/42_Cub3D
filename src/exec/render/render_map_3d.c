/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:31:51 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/25 23:05:46 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (render->pole == TOP)
		color = ft_get_pixel_color(&texture->top, render->offset_x,
				render->offset_y);
	if (render->pole == BOT)
		color = ft_get_pixel_color(&texture->bot, render->offset_x,
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
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH / 2)
		{
			set_pixel(mlx, render[(WIN_WIDTH / 2 * y) + x], x * 2, y * 2,
				texture);
			x++;
		}
		y++;
	}
	detroy_render(render);
	img_compression(mlx);
	return (0);
}