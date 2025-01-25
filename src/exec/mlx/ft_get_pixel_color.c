/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:04:03 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/25 23:14:09 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_pixel_color_hud(void *img, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	color = (*(int *)(data + (y * size_line + x * (bpp / 8))));
	if (color == (int)0xFF000000)
		return (0);
	return (color);
}

int	ft_get_pixel_color(t_texture *texture, float offsetx, float offsety)
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
