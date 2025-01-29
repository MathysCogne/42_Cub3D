/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:35:50 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 09:39:04 by achaisne         ###   ########.fr       */
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

t_render	*send_ray(int ind_v, int ind_h, t_player *player, char **grid, t_textures *textures)
{
	t_raycasting	rc;

	rc.ray.angle_h = normalize_angle_h((player->pos.angle_h - (HFVH / 2)
				+ HFVH * (ind_h / (((double)RESH) - 1))) * -1);
	rc.ray.angle_v = (player->pos.angle_v - (HFVV / 2) + HFVV * (ind_v
				/ (((double)RESV) - 1))) * -1;
	rc.ray.x = player->pos.x;
	rc.ray.y = player->pos.y;
	rc.ray.index = ind_v;
	rc.ray.z = HEIGT_PLAYER;
	set_collision(&rc, grid);
	return (get_render(player, &rc, grid, textures));
}

t_render	**ray_cast(t_player *player, char **grid, t_textures *textures)
{
	int			x;
	int			y;
	t_render	**render;

	render = malloc(sizeof(t_render) * RESH * RESV);
	if (!render)
		return (0);
	y = 0;
	while (y < RESV)
	{
		x = 0;
		while (x < RESH)
		{
			render[(RESH * y) + x] = send_ray(y, x, player, grid, textures);
			if (!render[(RESH * y) + x])
				return (0);
			x++;
		}
		y++;
	}
	return (render);
}
