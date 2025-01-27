/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:14:25 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 00:44:23 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: PARSE RGB OR TEXTURES FOR SKY AND CEIL
static short	valid_and_load_textures(t_env *env, t_textures *textures)
{
	textures->ea.value = mlx_xpm_file_to_image(env->mlx->id, textures->path_ea,
			&textures->ea.width, &textures->ea.height);
	textures->no.value = mlx_xpm_file_to_image(env->mlx->id, textures->path_no,
			&textures->no.width, &textures->no.height);
	textures->so.value = mlx_xpm_file_to_image(env->mlx->id, textures->path_so,
			&textures->so.width, &textures->so.height);
	textures->we.value = mlx_xpm_file_to_image(env->mlx->id, textures->path_we,
			&textures->we.width, &textures->we.height);
	textures->bot.value = mlx_xpm_file_to_image(env->mlx->id,
			"./assets/texture/BOT.xpm", &textures->bot.width,
			&textures->bot.height);
	textures->top.value = mlx_xpm_file_to_image(env->mlx->id,
			"./assets/texture/TOP.xpm", &textures->top.width,
			&textures->top.height);
	textures->weapon.value = mlx_xpm_file_to_image(env->mlx->id,
			"./assets/texture/weapon.xpm", &textures->weapon.width,
			&textures->weapon.height);
	textures->sprite.value = mlx_xpm_file_to_image(env->mlx->id,
			"./assets/texture/monster.xpm", &textures->sprite.width,
			&textures->sprite.height);
	if (!textures->ea.value || !textures->no.value || !textures->so.value
		|| !textures->we.value || !textures->bot.value || !textures->top.value
		|| !textures->weapon.value)
		return (1);
	return (0);
}

static short	new_img_mlx(t_mlx *mlx)
{
	mlx->render_pixel = mlx_new_imagsprite_dxe(mlx->id, WIN_WIDTH, WIN_HEIGHT);
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
