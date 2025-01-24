/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_placer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:42:25 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 18:48:23 by mcogne--         ###   ########.fr       */
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

short	update_player_angle(t_map *map, float angle_h, float angle_v)
{
	map->player.pos.angle_h += angle_h * ANGLE_SPEED;
	map->player.pos.angle_v += angle_v * ANGLE_SPEED;
	map->player.pos.angle_h = normalize_angle_h(map->player.pos.angle_h);
	map->player.pos.angle_v = normalize_angle_v(map->player.pos.angle_v);
	return (0);
}

static short	update_player_position(t_env *env, float x, float y)
{
	float	new_x;
	float	new_y;
	float	speed;

	speed = MOVE_SPEED;
	if (env->event->move_sprint)
		speed = SPRINT_SPEED;
	new_x = env->map->player.pos.x + x * speed;
	new_y = env->map->player.pos.y + y * speed;
	if (env->map->grid[(int)floor(new_x)][(int)floor(new_y)] == '1')
		return (0);
	env->map->player.pos.x = new_x;
	env->map->player.pos.y = new_y;
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
		update_player_position(env, cos(env->map->player.pos.angle_h * M_PI
				/ 180), sin(env->map->player.pos.angle_h * M_PI / 180));
	if (env->event->move_right)
		update_player_position(env, -cos(env->map->player.pos.angle_h * M_PI
				/ 180), -sin(env->map->player.pos.angle_h * M_PI / 180));
	if (env->event->angle_v_left)
		update_player_angle(env->map, -1, 0);
	if (env->event->angle_v_right)
		update_player_angle(env->map, 1, 0);
	if (env->event->angle_h_up)
		update_player_angle(env->map, 0, -1);
	if (env->event->angle_h_down)
		update_player_angle(env->map, 0, 1);
	return (0);
}
