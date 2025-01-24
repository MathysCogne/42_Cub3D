/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:36:53 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 19:11:26 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_render(t_env *env)
{
	static size_t	tick_count = 0;

	if (env->event->capture_mouse)
		mlx_mouse_move(env->mlx->id, env->mlx->win, WIN_WIDTH / 2, WIN_HEIGHT
			/ 2);
	if (tick_count > TICK_SPEED)
	{
		handler_move_player(env);
		render_env_3d(env->map, env->mlx, env->textures);
		handler_mini_map(env);
		mlx_put_image_to_window(env->mlx->id, env->mlx->win,
			env->mlx->render_pixel, 0, 0);
		tick_count = 0;
	}
	tick_count++;
	return (0);
}
