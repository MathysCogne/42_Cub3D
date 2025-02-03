/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:36:53 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 18:25:17 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	action_player_render(t_env *env)
{
	pthread_mutex_lock(&env->map->mutex_sprite);
	handler_action_hands_fights(env);
	pthread_mutex_unlock(&env->map->mutex_sprite);
	regen_stamina(env);
	handler_move_player(env);
}

int	loop_render(t_env *env)
{
	static size_t	tick_count = 0;

	if (env->event->capture_mouse)
		mlx_mouse_move(env->mlx->id, env->mlx->win, WIN_WIDTH / 2, WIN_HEIGHT
			/ 2);
	if (tick_count > TICK_SPEED)
	{
		action_player_render(env);
		if (render_map_3d(env->map, env->mlx, env->textures))
		{
			env->err = ERR_GAME;
			exit_user(env);
		}
		mlx_put_image_to_window(env->mlx->id, env->mlx->win,
			env->mlx->render_pixel, 0, 0);
		handler_hud(env);
		tick_count = 0;
	}
	tick_count++;
	return (0);
}
