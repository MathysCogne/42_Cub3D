/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:40:16 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 22:30:19 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	load_sprite(t_env *env, t_textures *textures)
{
	textures->monster[0].value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_MONSTER_00, &textures->monster[0].width,
			&textures->monster[0].height);
	textures->monster[1].value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_MONSTER_01, &textures->monster[1].width,
			&textures->monster[1].height);
	textures->monster[2].value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_MONSTER_02, &textures->monster[2].width,
			&textures->monster[2].height);
	textures->monster[3].value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_MONSTER_03, &textures->monster[3].width,
			&textures->monster[3].height);
	textures->musk[0].value = mlx_xpm_file_to_image(env->mlx->id, PATH_MUSK_00,
			&textures->musk[0].width, &textures->musk[0].height);
	textures->musk[1].value = mlx_xpm_file_to_image(env->mlx->id, PATH_MUSK_01,
			&textures->musk[1].width, &textures->musk[1].height);
	textures->musk[2].value = mlx_xpm_file_to_image(env->mlx->id, PATH_MUSK_02,
			&textures->musk[2].width, &textures->musk[2].height);
	textures->musk[3].value = mlx_xpm_file_to_image(env->mlx->id, PATH_MUSK_03,
			&textures->musk[3].width, &textures->musk[3].height);
	textures->musk[4].value = mlx_xpm_file_to_image(env->mlx->id, PATH_MUSK_04,
			&textures->musk[4].width, &textures->musk[4].height);
	textures->hud_bam.value = mlx_xpm_file_to_image(env->mlx->id, PATH_BAM,
			&textures->hud_bam.width, &textures->hud_bam.height);
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
	textures->menu_start.value = mlx_xpm_file_to_image(env->mlx->id, PATH_START,
			&textures->menu_start.width, &textures->menu_start.height);
	textures->menu_end.value = mlx_xpm_file_to_image(env->mlx->id, PATH_DIED,
			&textures->menu_end.width, &textures->menu_end.height);
	textures->menu_happy_end.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_END, &textures->menu_happy_end.width,
			&textures->menu_happy_end.height);
	return (0);
}

static short	load_textures_door_weapon(t_env *env, t_textures *textures)
{
	textures->weapon_off.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_WEAPON_OFF, &textures->weapon_off.width,
			&textures->weapon_off.height);
	textures->weapon_on.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_WEAPON_ON, &textures->weapon_on.width,
			&textures->weapon_on.height);
	textures->door_ea.value = mlx_xpm_file_to_image(env->mlx->id, PATH_DOOR_EA,
			&textures->door_ea.width, &textures->door_ea.height);
	textures->door_we.value = mlx_xpm_file_to_image(env->mlx->id, PATH_DOOR_WE,
			&textures->door_we.width, &textures->door_we.height);
	textures->door_no.value = mlx_xpm_file_to_image(env->mlx->id, PATH_DOOR_NO,
			&textures->door_no.width, &textures->door_no.height);
	textures->door_so.value = mlx_xpm_file_to_image(env->mlx->id, PATH_DOOR_SO,
			&textures->door_so.width, &textures->door_so.height);
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
	textures->bot_blood.value = mlx_xpm_file_to_image(env->mlx->id,
			PATH_BOT_BLOOD, &textures->bot_blood.width,
			&textures->bot_blood.height);
	return (0);
}

short	handler_load_textures(t_env *env, t_textures *textures)
{
	if (load_textures(env, textures))
		return (1);
	if (load_textures_door_weapon(env, textures))
		return (1);
	if (load_textures_hud(env, textures))
		return (1);
	if (load_sprite(env, textures))
		return (1);
	if (valid_textures(textures))
		return (1);
	return (0);
}
