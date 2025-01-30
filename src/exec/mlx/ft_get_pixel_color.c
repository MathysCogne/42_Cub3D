/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:04:03 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 23:16:28 by mcogne--         ###   ########.fr       */
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
	if (color == (int)HEX_BLACK)
		return (0);
	return (color);
}

int	ft_get_pixel_color(t_texture *texture, double offsetx, double offsety)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		color;

	data = mlx_get_data_addr(texture->value, &bpp, &size_line, &color);
	color = *(int *)(data + ((int)(offsety * texture->height) * size_line
				+ (int)(offsetx * texture->width) * (bpp / 8)));
	return (color);
}
