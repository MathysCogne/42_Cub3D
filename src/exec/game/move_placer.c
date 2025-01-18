/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_placer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:42:25 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/18 23:53:53 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	draw_player_2d(t_mlx *mlx, t_pos start, float angle, int color)
{
	t_pos	pos;
	t_pos	dir;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < RENDER_SIZE / 2)
	{
		j = 0;
		while (j < RENDER_SIZE / 2)
		{
			pos.x = start.x + j;
			pos.y = start.y + i;
			dir.x = start.x + cos(angle * M_PI / 180) * RENDER_SIZE * 0.15 + j;
			dir.y = start.y + sin(angle * M_PI / 180) * RENDER_SIZE * 0.15 + i;
			ft_put_pixel_in_img(mlx, pos, color);
			ft_put_pixel_in_img(mlx, dir, color);
			j++;
		}
		i++;
	}
	return (0);
}

static short	move_player(t_env *env, t_pos_player pos)
{
	t_pos	tile_pos;

	render_map_2d(env->map, env->mlx);
	tile_pos.x = pos.x * RENDER_SIZE;
	tile_pos.y = pos.y * RENDER_SIZE;
	draw_player_2d(env->mlx, tile_pos, env->map->player.angle, 0xFF9900);
	mlx_put_image_to_window(env->mlx->id, env->mlx->win, env->mlx->render_pixel,
		0, 0);
	return (0);
}

static short	update_player_angle(t_env *env, float angle)
{
	env->map->player.angle += angle * ANGLE_SPEED;
	if (env->map->player.angle >= 360)
		env->map->player.angle -= 360;
	else if (env->map->player.angle < 0)
		env->map->player.angle += 360;
	printf("New Player angle: %f\n", env->map->player.angle);
	return (0);
}

static short	update_player_position(t_env *env, float x, float y)
{
	t_pos_player	new_pos;

	new_pos.x = env->map->player.pos.x + x * MOVE_SPEED;
	new_pos.y = env->map->player.pos.y + y * MOVE_SPEED;
	env->map->player.pos = new_pos;
	printf("New Player position: %f %f\n", env->map->player.pos.x,
		env->map->player.pos.y);
	return (0);
}

short	handler_move_player(t_env *env, int keycode)
{
	if (keycode == KEY_W)
		update_player_position(env, 0, -1);
	else if (keycode == KEY_S)
		update_player_position(env, 0, 1);
	else if (keycode == KEY_A)
		update_player_position(env, -1, 0);
	else if (keycode == KEY_D)
		update_player_position(env, 1, 0);
	else if (keycode == KEY_LEFT)
		update_player_angle(env, -1);
	else if (keycode == KEY_RIGHT)
		update_player_angle(env, 1);
	move_player(env, env->map->player.pos);
	return (0);
}
