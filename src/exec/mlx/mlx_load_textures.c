/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:40:16 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 16:52:05 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	valid_texures(t_textures *textures)
{
	if (!textures->ea.value || !textures->no.value || !textures->so.value
		|| !textures->we.value)
		return (1);
	if ((textures->rgb_floor[0] == -1 && !textures->bot.value)
		|| (textures->rgb_ceiling[0] == -1 && !textures->top.value))
		return (1);
	if (!textures->weapon.value || !textures->door.value)
		return (1);
	return (0);
}

static short	load_textures(t_env *env, t_textures *textures)
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
			textures->path_bot, &textures->bot.width, &textures->bot.height);
	textures->top.value = mlx_xpm_file_to_image(env->mlx->id,
			textures->path_top, &textures->top.width, &textures->top.height);
	textures->weapon.value = mlx_xpm_file_to_image(env->mlx->id, PATH_WEAPON_00,
			&textures->weapon.width, &textures->weapon.height);
	textures->door.value = mlx_xpm_file_to_image(env->mlx->id, PATH_DOOR_00,
			&textures->door.width, &textures->door.height);
	return (0);
}

short	handler_load_textures(t_env *env, t_textures *textures)
{
	if (load_textures(env, textures))
		return (1);
	if (valid_texures(textures))
		return (1);
	return (0);
}
