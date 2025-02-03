/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:26:02 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:05:53 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	string_stats_player(t_mlx *mlx, t_player player)
{
	if (player.bullets <= 0)
		mlx_string_put(mlx->id, mlx->win, WIN_WIDTH * 0.9 / 2, WIN_HEIGHT
			* 0.70, COLOR_TXT_RED, TXT_NO_BULLETS);
	if (player.pv <= 3)
		mlx_string_put(mlx->id, mlx->win, WIN_WIDTH * 0.9 / 2, WIN_HEIGHT
			* 0.75, COLOR_TXT_RED, TXT_LOW_PV);
	if (player.stamina <= 2)
		mlx_string_put(mlx->id, mlx->win, WIN_WIDTH * 0.9 / 2, WIN_HEIGHT
			* 0.80, COLOR_TXT_RED, TXT_LOW_STAMINA);
}

static void	string_orientation(t_mlx *mlx, t_pos_player pos)
{
	char	*direction;

	direction = "";
	if (pos.angle_h >= 337.5 || pos.angle_h < 22.5)
		direction = "E";
	else if (pos.angle_h >= 22.5 && pos.angle_h < 67.5)
		direction = "NE";
	else if (pos.angle_h >= 67.5 && pos.angle_h < 112.5)
		direction = "N";
	else if (pos.angle_h >= 112.5 && pos.angle_h < 157.5)
		direction = "NW";
	else if (pos.angle_h >= 157.5 && pos.angle_h < 202.5)
		direction = "W";
	else if (pos.angle_h >= 202.5 && pos.angle_h < 247.5)
		direction = "SW";
	else if (pos.angle_h >= 247.5 && pos.angle_h < 292.5)
		direction = "S";
	else if (pos.angle_h >= 292.5 && pos.angle_h < 337.5)
		direction = "SE";
	mlx_string_put(mlx->id, mlx->win, 75, 155, COLOR_TXT_INFO, direction);
}

static void	string_door(t_mlx *mlx, t_map *map, t_pos_player pos)
{
	short	door;

	door = player_adjacent_door(map->grid, (int)pos.y, (int)pos.x);
	if (door == CARAC_DOOR_OPEN)
		mlx_string_put(mlx->id, mlx->win, WIN_WIDTH * 0.8 / 2, WIN_HEIGHT
			* 0.075, COLOR_TXT_INFO, TXT_DOOR_CLOSE);
	else if (door == CARAC_DOOR)
		mlx_string_put(mlx->id, mlx->win, WIN_WIDTH * 0.8 / 2, WIN_HEIGHT
			* 0.075, COLOR_TXT_INFO, TXT_DOOR_OPEN);
}

void	handler_put_strings(t_env *env)
{
	string_door(env->mlx, env->map, env->map->player.pos);
	string_orientation(env->mlx, env->map->player.pos);
	string_stats_player(env->mlx, env->map->player);
}
