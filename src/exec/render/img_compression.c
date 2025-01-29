/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_compression.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:04:30 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 09:10:25 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	average_color2(int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	r = (((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF)) / 2;
	g = (((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF)) / 2;
	b = (((color1) & 0xFF) + ((color2) & 0xFF)) / 2;
	return ((r << 16) | (g << 8) | b);
}

int	average_color4(int color1, int color2, int color3, int color4)
{
	int	r;
	int	g;
	int	b;

	r = (((color1 >> 16) & 0xFF) + ((color2 >> 16) & 0xFF)
			+ ((color3 >> 16) & 0xFF) + ((color4 >> 16) & 0xFF)) / 4;
	g = (((color1 >> 8) & 0xFF) + ((color2 >> 8) & 0xFF)
			+ ((color3 >> 8) & 0xFF) + ((color4 >> 8) & 0xFF)) / 4;
	b = (((color1) & 0xFF) + ((color2) & 0xFF)
			+ ((color3) & 0xFF) + ((color4) & 0xFF)) / 4;
	return ((r << 16) | (g << 8) | b);
}

void	set_pixel(int x, int y, t_mlx *mlx)
{
	t_pos	pos;
	int		color;

	pos.x = x + 1;
	pos.y = y;
	color = average_color2(mlx->render_pixel_data[y * (mlx->size_line
				/ 4) + x], mlx->render_pixel_data[y * (mlx->size_line
				/ 4) + x + 2]);
	ft_put_pixel_in_img(mlx, pos, color);
	pos.x = x;
	pos.y = y + 1;
	color = average_color2(mlx->render_pixel_data[y * (mlx->size_line
				/ 4) + x], mlx->render_pixel_data[(y + 2)
			* (mlx->size_line / 4) + x]);
	ft_put_pixel_in_img(mlx, pos, color);
	pos.x = x + 1;
	pos.y = y + 1;
	color = average_color4(mlx->render_pixel_data[y * (mlx->size_line
				/ 4) + x], mlx->render_pixel_data[y * (mlx->size_line
				/ 4) + x + 2], mlx->render_pixel_data[(y + 2)
			* (mlx->size_line / 4) + x], mlx->render_pixel_data[(y + 2)
			* (mlx->size_line / 4) + x + 2]);
	ft_put_pixel_in_img(mlx, pos, color);
}

void	bi_interpolation_decompression(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y + 2 < WIN_HEIGHT)
	{
		x = 0;
		while (x + 2 < WIN_WIDTH)
		{
			set_pixel(x, y, mlx);
			x += 2;
		}
		y += 2;
	}
}
