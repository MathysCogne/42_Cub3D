/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_placer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:42:25 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 02:44:05 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static short	draw_player_2d(t_mlx *mlx, t_pos start, float angle, int color)
// {
// 	t_pos	pos;
// 	t_pos	dir;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < RENDER_SIZE_2D / 2)
// 	{
// 		j = 0;
// 		while (j < RENDER_SIZE_2D / 2)
// 		{
// 			pos.x = start.x + j;
// 			pos.y = start.y + i;
// 			dir.x = start.x + cos(angle * M_PI / 180) * RENDER_SIZE_2D * 0.15
// 				+ j;
// 			dir.y = start.y + sin(angle * M_PI / 180) * RENDER_SIZE_2D * 0.15
// 				+ i;
// 			ft_put_pixel_in_img(mlx, pos, color);
// 			ft_put_pixel_in_img(mlx, dir, color);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

short	update_player_angle(t_env *env, float angle_h, float angle_v)
{
	env->map->player.pos.angle_h += angle_h * ANGLE_SPEED;
	env->map->player.pos.angle_v += angle_v * ANGLE_SPEED;
	if (env->map->player.pos.angle_h >= ANGLE_X_MAX)
		env->map->player.pos.angle_h -= ANGLE_X_MAX;
	else if (env->map->player.pos.angle_h < 0)
		env->map->player.pos.angle_h += ANGLE_X_MAX;
	//
	if (env->map->player.pos.angle_v >= ANGLE_Y_MAX)
		env->map->player.pos.angle_v = ANGLE_Y_MAX;
	else if (env->map->player.pos.angle_v <= -ANGLE_Y_MAX)
		env->map->player.pos.angle_v = -ANGLE_Y_MAX;
	if (DEBUG_MODE)
		printf("New Player angle: %f | %f\n", env->map->player.pos.angle_h,
			env->map->player.pos.angle_v);
	return (0);
}

static short	update_player_position(t_env *env, float x, float y)
{
	float	new_x;
	float	new_y;

	new_x = env->map->player.pos.x + x * MOVE_SPEED;
	new_y = env->map->player.pos.y + y * MOVE_SPEED;
	if (env->map->grid[(int)floor(new_x)][(int)floor(new_y)] == '1')
		return (0);
	env->map->player.pos.x = new_x;
	env->map->player.pos.y = new_y;
	if (DEBUG_MODE)
		printf("New player position: (%f, %f)\n", env->map->player.pos.x,
			env->map->player.pos.y);
	return (1);
}

short	handler_move_player(t_env *env)
{
	if (env->event->move_forward)
		update_player_position(env, -sin(env->map->player.pos.angle_h * M_PI
				/ 180), cos(env->map->player.pos.angle_h * M_PI / 180));
	if (env->event->move_back)
		update_player_position(env, sin(env->map->player.pos.angle_h * M_PI
				/ 180), -cos(env->map->player.pos.angle_h * M_PI / 180));
	if (env->event->move_left)
		update_player_position(env, -1, 0);
	if (env->event->move_right)
		update_player_position(env, 1, 0);
	if (env->event->angle_v_left)
		update_player_angle(env, -1, 0);
	if (env->event->angle_v_right)
		update_player_angle(env, 1, 0);
	if (env->event->angle_h_up)
		update_player_angle(env, 0, -1);
	if (env->event->angle_h_down)
		update_player_angle(env, 0, 1);
	return (0);
}
