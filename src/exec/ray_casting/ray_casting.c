/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:35:50 by achaisne          #+#    #+#             */
/*   Updated: 2025/02/02 14:16:22 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	detroy_render(t_render **render)
{
	int	x;
	int	y;

	y = 0;
	while (y < RESV)
	{
		x = 0;
		while (x < RESH)
		{
			if (render[(RESH * y) + x])
				free(render[(RESH * y) + x]);
			x++;
		}
		y++;
	}
	free(render);
}

int	is_collision(t_raycasting *rc, char **grid)
{
	if (rc->ray_dir_x > 0 && round(rc->ray.x) == rc->ray.x
		&& ft_strchr(WALL_DOOR, grid[(int)rc->ray.y][(int)rc->ray.x]))
		return (1);
	if (rc->ray_dir_y > 0 && round(rc->ray.y) == rc->ray.y
		&& ft_strchr(WALL_DOOR, grid[(int)rc->ray.y][(int)rc->ray.x]))
		return (1);
	if (rc->ray_dir_x < 0 && round(rc->ray.x) == rc->ray.x
		&& ft_strchr(WALL_DOOR, grid[(int)rc->ray.y][(int)rc->ray.x - 1]))
		return (1);
	if (rc->ray_dir_y < 0 && round(rc->ray.y) == rc->ray.y
		&& ft_strchr(WALL_DOOR, grid[(int)rc->ray.y - 1][(int)rc->ray.x]))
		return (1);
	if (rc->ray_dir_z > 0 && rc->ray.z == HEIGHT)
		return (1);
	if (rc->ray_dir_z < 0 && rc->ray.z == 0)
		return (1);
	return (0);
}

void	set_collision(t_raycasting *rc, char **grid)
{
	rc->ray_dir_x = cos(degree_to_radian(rc->ray.angle_h));
	if (rc->ray_dir_x == 0)
		rc->ray_dir_x += 1e-9;
	rc->ray_dir_y = sin(degree_to_radian(rc->ray.angle_h));
	if (rc->ray_dir_y == 0)
		rc->ray_dir_y += 1e-9;
	rc->ray_dir_z = sin(degree_to_radian(rc->ray.angle_v));
	if (rc->ray_dir_z == 0)
		rc->ray_dir_z += 1e-9;
	while (!is_collision(rc, grid))
	{
		set_next_x(rc);
		set_next_y(rc);
		set_next_z(rc);
		set_ray(rc);
	}
}

t_render	*send_ray(t_pos *pos, t_player *player,
						char **grid, t_textures *textures)
{
	t_raycasting	rc;

	rc.ray.angle_h = normalize_angle_h((player->pos.angle_h - (FOVH / 2)
				+ FOVH * (pos->x / (((double)RESH) - 1))) * -1);
	rc.ray.angle_v = (player->pos.angle_v - (FOVV / 2) + FOVV * (pos->y
				/ (((double)RESV) - 1))) * -1;
	rc.ray.x = player->pos.x;
	rc.ray.y = player->pos.y;
	rc.ray.z = HEIGT_PLAYER;
	set_collision(&rc, grid);
	return (get_render(player, &rc, grid, textures));
}

t_render	**ray_cast(t_player *player, char **grid, t_textures *textures)
{
	t_render	**render;
	t_pos		pos;

	render = ft_calloc(sizeof(t_render), RESH * RESV);
	if (!render)
		return (0);
	pos.y = 0;
	while (pos.y < RESV)
	{
		pos.x = 0;
		while (pos.x < RESH)
		{
			render[(RESH * pos.y) + pos.x]
				= send_ray(&pos, player, grid, textures);
			if (!render[(RESH * pos.y) + pos.x])
				return (detroy_render(render), NULL);
			pos.x++;
		}
		pos.y++;
	}
	return (render);
}
