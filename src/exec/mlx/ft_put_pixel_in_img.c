/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_in_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:29:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 00:46:57 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	ft_put_pixel_in_img(t_mlx *mlx, t_pos pos, int color)
{
	if (!mlx || !mlx->render_pixel_data || pos.x >= WIN_WIDTH
		|| pos.y >= WIN_HEIGHT)
		return (1);
	mlx->render_pixel_data[pos.y * (mlx->size_line / 4) + pos.x] = color;
	return (0);
}
