/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:31:51 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/23 08:21:41 by achaisne         ###   ########.fr       */
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

int average_color2(int color1, int color2)
{
    int r = (((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF)) / 2;
    int g = (((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF)) / 2;
    int b = (((color1) & 0xFF) + ((color2) & 0xFF)) / 2;

    return (r << 16) | (g << 8) | b;
}

int average_color4(int color1, int color2, int color3, int color4)
{
    int r = (((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF) + ((color3 >> 16) & 0xFF) + ((color4 >> 16) & 0xFF)) / 4;
    int g = (((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF) + ((color3 >> 8) & 0xFF) + ((color4 >> 8) & 0xFF)) / 4;
    int b = (((color1) & 0xFF) + ((color2) & 0xFF) + ((color3) & 0xFF) + ((color4) & 0xFF)) / 4;

    return (r << 16) | (g << 8) | b;
}

void	img_compression( t_mlx *mlx)
{
	t_pos	pos;
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y + 2 < (int)RESV)
	{
		x = 0;
		while (x + 2 < (int)RESH)
		{
			pos.x = x + 1;
			pos.y = y;
			color = average_color2(
				mlx->render_pixel_data[y * (mlx->size_line / 4) + x],
				mlx->render_pixel_data[y * (mlx->size_line / 4) + x + 2]);
			ft_put_pixel_in_img(mlx, pos, color);


			pos.x = x;
			pos.y = y + 1;
			color = average_color2(
				mlx->render_pixel_data[y * (mlx->size_line / 4) + x],
				mlx->render_pixel_data[(y + 2) * (mlx->size_line / 4) + x]);
			ft_put_pixel_in_img(mlx, pos, color);


			pos.x = x + 1;
			pos.y = y + 1;
			color = average_color4(
				mlx->render_pixel_data[y * (mlx->size_line / 4) + x],
				mlx->render_pixel_data[y * (mlx->size_line / 4) + x + 2],
				mlx->render_pixel_data[(y + 2) * (mlx->size_line / 4) + x],
				mlx->render_pixel_data[(y + 2) * (mlx->size_line / 4) + x + 2]);
			ft_put_pixel_in_img(mlx, pos, color);

			x += 2;
		}
		y += 2;
	}
}

short	render_env_3d(t_map *map, t_mlx *mlx, t_textures *texture)
{
	int			x;
	int			y;

	map->player.pos.angle_v = 0.0;

	t_render **render = ray_cast(&map->player, map->grid);
	if (!render)
		return (1);
	y = 0;
	while (y < (int)RESV / 2)
	{
		x = 0;
		while (x < (int)RESH / 2 )
		{
			set_pixel(mlx, render[((int)RESH / 2 * y) + x], x * 2, y * 2, texture);
			x++;
		}
		y++;
	}
	detroy_render(render);
	img_compression(mlx);
	return (0);
}