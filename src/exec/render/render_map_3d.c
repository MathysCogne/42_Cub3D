/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:31:51 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/22 01:32:24 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"
#include "cub3d.h"

static int get_pixel(t_texture *texture, float offsetx, float offsety)
{
	int pixel_x = (int)(offsetx * texture->width);
	int pixel_y = (int)(offsety * texture->height);
	int bpp, size_line, endian;
	char *data = mlx_get_data_addr(texture->value, &bpp, &size_line, &endian);
	int offset = (pixel_y * size_line) + (pixel_x * (bpp / 8));
	int color = *(int *)(data + offset);
    return (color);
}


static void	set_pixel(t_mlx *mlx, t_render *render, int x, int y, t_textures *texture)
{
	t_pos	pos;
	int		color;

	if (render->pole == NO)
		color = get_pixel(&texture->no, render->offset_x, render->offset_y);
	if (render->pole == SO)
		color = get_pixel(&texture->so, render->offset_x, render->offset_y);
	if (render->pole == EA)
		color = get_pixel(&texture->ea, render->offset_x, render->offset_y);
	if (render->pole == WE)
		color = get_pixel(&texture->we, render->offset_x, render->offset_y);
	if (render->pole == TOP)
		color = get_pixel(&texture->top, render->offset_x, render->offset_y);
	if (render->pole == BOT)
		color = get_pixel(&texture->bot, render->offset_x, render->offset_y);
	pos.x = x;
	pos.y = y;
	ft_put_pixel_in_img(mlx, pos, color);
}

short	render_env_3d(t_map *map, t_mlx *mlx, t_textures *texture)
{
	int			x;
	int			y;

	map->player.pos.x = 5;
	map->player.pos.y = 6;
	map->player.pos.angle_v = 0;

	t_render **render = ray_cast(&map->player, map->grid);
	if (!render)
		return (1);
	y = 0;
	while (y < (int)RESV)
	{
		x = 0;
		while (x < (int)RESH)
		{
			set_pixel(mlx, render[((int)RESH * y) + x], x, y, texture);
			x++;
		}
		y++;
	}
	detroy_render(render);
	return (0);
}