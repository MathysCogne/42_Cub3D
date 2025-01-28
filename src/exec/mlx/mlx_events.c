/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:45:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/28 19:49:41 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	click_mouse_event(int keycode, int h, int v, t_env *env)
{
	(void)h, (void)v;
	if (keycode && !env->event->capture_mouse)
	{
		env->event->capture_mouse = 1;
		mlx_mouse_hide(env->mlx->id, env->mlx->win);
	}
	if (keycode == KEY_MOUSE_RIGHT)
	{
		if (!env->event->click_left)
			env->event->click_left = 1;
		else
			env->event->click_left = 0;
	}
	if (keycode == KEY_MOUSE_LEFT)
	{
		handler_action_weapon(env);
		env->event->click_right = 1;
	}
	return (0);
}

static int	move_mouse_event(int pos_h, int pos_v, t_env *env)
{
	static int	last_pos_h;
	static int	last_pos_v;

	if (!last_pos_h)
		last_pos_h = pos_h;
	if (!last_pos_v)
		last_pos_v = pos_v;
	if (!env->event->capture_mouse)
		return (0);
	if (pos_h == WIN_WIDTH / 2 || pos_v == WIN_HEIGHT / 2)
	{
		last_pos_h = pos_h;
		last_pos_v = pos_v;
		return (0);
	}
	if (last_pos_h != pos_h || last_pos_v != pos_v)
		update_player_angle(env->map, (last_pos_h - pos_h) * -1 * MOUSE_SPEED,
			(last_pos_v - pos_v) * -1 * MOUSE_SPEED);
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
	else if (keycode == KEY_SHIFT || keycode == KEY_CAPSLOCK)
		env->event->move_sprint = 0;
	return (0);
}

static int	key_press(int keycode, t_env *env)
{
	if (!env->event->menu_start && keycode)
		env->event->menu_start = 1;
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
	else if (keycode == KEY_SHIFT || keycode == KEY_CAPSLOCK)
		env->event->move_sprint = 1;
	else if (keycode == KEY_SPACE)
		handler_door(env);
	return (0);
}

short	ft_mlx_init_events(t_env *env)
{
	mlx_hook(env->mlx->win, 2, 1L << 0, key_press, env);
	mlx_hook(env->mlx->win, 3, 1L << 1, key_release, env);
	mlx_hook(env->mlx->win, 17, 1L << 17, exit_user, env);
	mlx_hook(env->mlx->win, 6, 1L << 6, move_mouse_event, env);
	mlx_mouse_hook(env->mlx->win, click_mouse_event, env);
	return (0);
}
