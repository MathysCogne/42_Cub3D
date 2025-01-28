/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:36:53 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 22:06:22 by mcogne--         ###   ########.fr       */
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
		regen_stamina(env);
		handler_move_player(env);
		render_map_3d(env->map, env->mlx, env->textures);
		mlx_put_image_to_window(env->mlx->id, env->mlx->win,
			env->mlx->render_pixel, 0, 0);
		handler_hud(env);
		tick_count = 0;
	}
	tick_count++;
	return (0);
}
