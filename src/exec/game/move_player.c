/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:42:25 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:03:37 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_angle(t_map *map, double angle_h, double angle_v)
{
	map->player.pos.angle_h += angle_h * ANGLE_SPEED;
	map->player.pos.angle_v += angle_v * ANGLE_SPEED;
	map->player.pos.angle_h = normalize_angle_h(map->player.pos.angle_h);
	map->player.pos.angle_v = normalize_angle_v(map->player.pos.angle_v);
}

static short	update_player_position(t_env *env, double x, double y)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = MOVE_SPEED;
	if (env->event->move_sprint && !action_sprint(env->map, x, y))
		speed = SPRINT_SPEED;
	new_x = env->map->player.pos.y + x * speed;
	new_y = env->map->player.pos.x + y * speed;
	if (!ft_strchr(MOVE_COLISION, env->map->grid
			[(int)floor(env->map->player.pos.y)][(int)floor(new_y)]))
		env->map->player.pos.x = new_y;
	if (!ft_strchr(MOVE_COLISION, env->map->grid
			[(int)floor(new_x)][(int)floor(env->map->player.pos.x)]))
		env->map->player.pos.y = new_x;
	return (0);
}

void	handler_move_player(t_env *env)
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
}
