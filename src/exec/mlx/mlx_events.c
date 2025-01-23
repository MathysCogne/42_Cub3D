/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:45:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/23 17:41:22 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	exit_user(t_env *env)
{
	cleanup(env);
	ft_printf(NAME "Goodbye 👋\n");
	exit(0);
}
static int	key_press(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit_user(env);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D)
		handler_move_player(env, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_TOP
		|| keycode == KEY_BOT)
		handler_move_player(env, keycode);
	return (0);
}

short	ft_mlx_init_events(t_env *env)
{
	mlx_hook(env->mlx->win, 2, 1L << 0, key_press, env);
	mlx_hook(env->mlx->win, 17, 1L << 17, exit_user, env);
	return (0);
}
