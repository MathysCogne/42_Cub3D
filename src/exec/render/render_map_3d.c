/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:31:51 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/25 12:30:01 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray_casting.h"

static int	get_pixel(t_texture *texture, float offsetx, float offsety)
{
	int		pixel_x;
	int		pixel_y;
	char	*data;
	int		offset;
	int		color;

	pixel_x = (int)(offsetx * texture->width);
	pixel_y = (int)(offsety * texture->height);
	int bpp, size_line, endian;
	data = mlx_get_data_addr(texture->value, &bpp, &size_line, &endian);
	offset = (pixel_y * size_line) + (pixel_x * (bpp / 8));
	color = *(int *)(data + offset);
	return (color);
}

static void	set_pixel(t_mlx *mlx, t_render *render, int x, int y,
		t_textures *texture)
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