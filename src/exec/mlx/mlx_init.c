/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:14:25 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/20 21:02:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	valid_and_load_textures(t_env *env, t_textures *textures)
{
	textures->t_ea = mlx_xpm_file_to_image(env->mlx->id, textures->path_ea,
			&textures->t_width, &textures->t_height);
	textures->t_no = mlx_xpm_file_to_image(env->mlx->id, textures->path_no,
			&textures->t_width, &textures->t_height);
	textures->t_so = mlx_xpm_file_to_image(env->mlx->id, textures->path_so,
			&textures->t_width, &textures->t_height);
	textures->t_we = mlx_xpm_file_to_image(env->mlx->id, textures->path_we,
			&textures->t_width, &textures->t_height);
	if (!textures->t_ea || !textures->t_no || !textures->t_so
		|| !textures->t_we)
		return (1);
	return (0);
}

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
	if (valid_and_load_textures(env, env->textures))
		return (1);
	if (new_img_mlx(mlx))
		return (1);
	return (0);
}
