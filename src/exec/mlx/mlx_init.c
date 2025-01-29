/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:14:25 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/29 16:46:10 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	new_img_mlx(t_mlx *mlx)
{
	mlx->render_pixel = mlx_new_image(mlx->id, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->render_pixel)
		return (1);
	mlx->render_pixel_data = (int *)mlx_get_data_addr(mlx->render_pixel,
			&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
	if (!mlx->render_pixel_data)
		return (1);
	return (0);
}

short	ft_mlx_init_win(t_env *env, t_mlx *mlx)
{
	mlx->id = mlx_init();
	if (!mlx->id)
		return (1);
	mlx->win = mlx_new_window(mlx->id, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!mlx->win)
		return (1);
	if (handler_load_textures(env, env->textures))
		return (1);
	if (new_img_mlx(mlx))
		return (1);
	return (0);
}
