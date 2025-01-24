/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:45:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 01:56:16 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_mouse_event(int pos_h, int pos_v, t_env *env)
{
	static int	last_pos_h;
	static int	last_pos_v;

	if (!last_pos_h)
		last_pos_h = pos_h;
	if (!last_pos_v)
		last_pos_v = pos_v;
	//
	if (last_pos_h < pos_h)
		update_player_angle(env, (last_pos_h - pos_h) * MOUSE_SPEED, 0);
	else if (last_pos_h > pos_h)
		update_player_angle(env, (last_pos_h - pos_h) * MOUSE_SPEED, 0);
	//
	if (last_pos_v < pos_v)
		update_player_angle(env, 0, (last_pos_v - pos_v) * MOUSE_SPEED);
	else if (last_pos_v > pos_v)
		update_player_angle(env, 0, (last_pos_v - pos_v) * MOUSE_SPEED);
	//
	last_pos_h = pos_h;
	last_pos_v = pos_v;
	return (0);
}

static int	key_release(int keycode, t_env *env)
{
	if (keycode == KEY_W)
		env->event->move_forward = 0;
	else if (keycode == KEY_S)
		env->event->move_back = 0;
	else if (keycode == KEY_A)
		env->event->move_left = 0;
	else if (keycode == KEY_D)
		env->event->move_right = 0;
	else if (keycode == KEY_LEFT)
		env->event->angle_v_left = 0;
	else if (keycode == KEY_RIGHT)
		env->event->angle_v_right = 0;
	else if (keycode == KEY_TOP)
		env->event->angle_h_up = 0;
	else if (keycode == KEY_BOT)
		env->event->angle_h_down = 0;
	return (0);
}

static int	key_press(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit_user(env);
	else if (keycode == KEY_W)
		env->event->move_forward = 1;
	else if (keycode == KEY_S)
		env->event->move_back = 1;
	else if (keycode == KEY_A)
		env->event->move_left = 1;
	else if (keycode == KEY_D)
		env->event->move_right = 1;
	else if (keycode == KEY_LEFT)
		env->event->angle_v_left = 1;
	else if (keycode == KEY_RIGHT)
		env->event->angle_v_right = 1;
	else if (keycode == KEY_TOP)
		env->event->angle_h_up = 1;
	else if (keycode == KEY_BOT)
		env->event->angle_h_down = 1;
	return (0);
}

static int	loop_render(t_env *env)
{
	static size_t	tick_count = 0;

	if (tick_count > TICK_SPEED)
	{
		handler_move_player(env);
		render_env_3d(env->map, env->mlx, env->textures);
		mlx_put_image_to_window(env->mlx->id, env->mlx->win,
			env->mlx->render_pixel, 0, 0);
		tick_count = 0;
	}
	tick_count++;
	return (0);
}

short	ft_mlx_init_events(t_env *env)
{
	mlx_loop_hook(env->mlx->id, loop_render, env);
	mlx_hook(env->mlx->win, 2, 1L << 0, key_press, env);
	mlx_hook(env->mlx->win, 3, 1L << 1, key_release, env);
	mlx_hook(env->mlx->win, 17, 1L << 17, exit_user, env);
	mlx_hook(env->mlx->win, 6, 1L << 6, move_mouse_event, env);
	return (0);
}
