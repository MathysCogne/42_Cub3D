/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_stats_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:39:16 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/28 21:10:50 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_status_life_player(t_env *env, t_map *map)
{
	if (map->player.pv <= 0)
		env->event->menu_died = 1;
}

static void	put_stamina(t_env *env, t_player player)
{
	t_pos	pos;
	int		width_to_print;

	pos.x = WIN_WIDTH * 0.02 + env->textures->hud_card_id.width
		+ env->textures->hud_stamina.height + 40;
	pos.y = WIN_HEIGHT * 0.97 - env->textures->hud_stamina.height;
	helper_mlx_put_hud_to_win(env, env->textures->hud_stamina, pos);
	width_to_print = (player.stamina * 100) / START_STAMINA;
	pos.x = WIN_WIDTH * 0.02 + env->textures->hud_card_id.width
		+ env->textures->hud_stamina.height + 40 + 25;
	pos.y = WIN_HEIGHT * 0.97 - env->textures->hud_stamina.height + 4;
	helper_mlx_put_width_max_hud_to_win(env, env->textures->hud_stamina_rod,
		pos, width_to_print);
}

static void	put_pv(t_env *env, t_player player)
{
	t_pos	pos;
	int		height_to_print;

	pos.x = WIN_WIDTH * 0.02 + env->textures->hud_card_id.width + 20;
	pos.y = WIN_HEIGHT * 0.98 - env->textures->hud_pv.height;
	helper_mlx_put_hud_to_win(env, env->textures->hud_pv, pos);
	height_to_print = (player.pv * env->textures->hud_pv_rod.height) / START_PV;
	pos.x = WIN_WIDTH * 0.02 + env->textures->hud_card_id.width + 20;
	pos.y = WIN_HEIGHT * 0.98 - env->textures->hud_pv.height + 7;
	helper_mlx_put_height_start_hud_to_win(env, env->textures->hud_pv_rod, pos,
		height_to_print);
}

static void	put_card_id(t_env *env)
{
	t_pos	pos;
	char	*ammo;

	ammo = ft_strjoin("AMMO: ", ft_itoa(env->map->player.bullets));
	pos.x = WIN_WIDTH * 0.02;
	pos.y = WIN_HEIGHT * 0.98 - env->textures->hud_card_id.height;
	helper_mlx_put_hud_to_win(env, env->textures->hud_card_id, pos);
	mlx_string_put(env->mlx->id, env->mlx->win, WIN_WIDTH * 0.043, WIN_HEIGHT
		* 0.948, COLOR_TXT_INFO, ammo);
	free(ammo);
}

short	handler_hud_stats_player(t_env *env)
{
	check_status_life_player(env, env->map);
	put_card_id(env);
	put_pv(env, env->map->player);
	put_stamina(env, env->map->player);
	return (0);
}
