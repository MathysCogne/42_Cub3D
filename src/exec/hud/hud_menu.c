/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:45:16 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:15:31 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	menu_happy_end(t_env *env)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	helper_mlx_put_hud_to_win(env, env->textures->menu_happy_end, pos);
}

static void	menu_start(t_env *env)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	helper_mlx_put_hud_to_win(env, env->textures->menu_start, pos);
}

static void	menu_died(t_env *env)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	helper_mlx_put_hud_to_win(env, env->textures->menu_end, pos);
}

void	handler_menu(t_env *env)
{
	if (env->event->menu_died)
		menu_died(env);
	if (!env->event->menu_start)
		menu_start(env);
	if (env->event->menu_happy_end)
		menu_happy_end(env);
}
