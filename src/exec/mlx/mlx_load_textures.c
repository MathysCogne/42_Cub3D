/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:40:16 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/28 01:32:09 by achaisne         ###   ########.fr       */
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
	if (!textures->weapon_off.value || !textures->weapon_on.value
		|| !textures->door.value)
		return (1);
	if (!textures->hud_border_map.value || !textures->hud_card_id.value
		|| !textures->hud_pv.value || !textures->hud_pv_rod.value
		|| !textures->hud_stamina.value || !textures->hud_stamina_rod.value)
		return (ft_printf("HERE\n"), 1);
	return (0);
}

static short	load_textures_hud(t_env *env, t_textures *textures)
{
	textures->hud_border_map.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_BORDER_MAP, &textures->hud_border_map.width,
			&textures->hud_border_map.height);
	textures->hud_card_id.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_CARD_ID, &textures->hud_card_id.width,
			&textures->hud_card_id.height);
	textures->hud_pv.value = mlx_xpm_file_to_image(env->mlx->id, PATH_PV,
			&textures->hud_pv.width, &textures->hud_pv.height);
	textures->hud_pv_rod.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_PV_ROD, &textures->hud_pv_rod.width,
			&textures->hud_pv_rod.height);
	textures->hud_stamina.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_STAMINA, &textures->hud_stamina.width,
			&textures->hud_stamina.height);
	textures->hud_stamina_rod.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_STAMINA_ROD, &textures->hud_stamina_rod.width,
			&textures->hud_stamina_rod.height);
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
	textures->weapon_off.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_WEAPON_OFF, &textures->weapon_off.width,
			&textures->weapon_off.height);
	textures->weapon_on.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_WEAPON_ON, &textures->weapon_on.width,
			&textures->weapon_on.height);
	textures->door.value = mlx_xpm_file_to_image(env->mlx->id, PATH_DOOR_00,
			&textures->door.width, &textures->door.height);
		textures->sprite.value = mlx_xpm_file_to_image(env->mlx->id, PATH_SPRITE,
			&textures->sprite.width, &textures->sprite.height);
	return (0);
}

short	handler_load_textures(t_env *env, t_textures *textures)
{
	if (load_textures(env, textures))
		return (1);
	if (load_textures_hud(env, textures))
		return (1);
	if (valid_texures(textures))
		return (1);
	return (0);
}
