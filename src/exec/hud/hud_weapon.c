/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_weapon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:57:05 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:05:39 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handler_waepon(t_env *env)
{
	t_pos	pos;

	pos.x = (WIN_WIDTH - env->textures->weapon_off.width) / 2;
	pos.y = WIN_HEIGHT - env->textures->weapon_off.height;
	if (env->event->click_left)
		helper_mlx_put_hud_to_win(env, env->textures->weapon_on, pos);
	else
		helper_mlx_put_hud_to_win(env, env->textures->weapon_off, pos);
}
