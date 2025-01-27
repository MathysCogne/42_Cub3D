/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:45:34 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/26 14:27:41 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_collision(t_ray *ray, t_raycasting *rc, char **grid)
{
	if (rc->ray_dir_x > 0 && round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x] == '1')
		return (1);
	if (rc->ray_dir_y > 0 && round(ray->y) == ray->y
		&& grid[(int)ray->y][(int)ray->x] == '1')
		return (1);
	if (rc->ray_dir_x < 0 && round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x - 1] == '1')
		return (1);
	if (rc->ray_dir_y < 0 && round(ray->y) == ray->y
		&& grid[(int)ray->y - 1][(int)ray->x] == '1')
		return (1);
	if (rc->ray_dir_z > 0 && ray->z == HEIGHT)
		return (1);
	if (rc->ray_dir_z < 0 && ray->z == 0)
		return (1);
	return (0);
}

void	set_collision(t_ray *ray, char **grid, t_raycasting *rc)
{
	rc->ray_dir_x = cos(degree_to_radian(ray->angle_h));
	if (rc->ray_dir_x == 0)
		rc->ray_dir_x += 1e-9;
	rc->ray_dir_y = sin(degree_to_radian(ray->angle_h));
	if (rc->ray_dir_y == 0)
		rc->ray_dir_y += 1e-9;
	rc->ray_dir_z = sin(degree_to_radian(ray->angle_v));
	if (rc->ray_dir_z == 0)
		rc->ray_dir_z += 1e-9;
	while (!is_collision(ray, rc, grid))
	{
		set_next_x(ray, rc);
		set_next_y(ray, rc);
		set_next_z(ray, rc);
		set_ray(ray, rc);
	}
}

void	set_offset(t_render *render, t_ray *ray)
{
	if (render->pole != EA && render->pole != WE)
		render->offset_x = fabs(ray->x - floor(ray->x));
	else
		render->offset_x = fabs(ray->y - floor(ray->y));
	if (render->pole != BOT && render->pole != TOP)
		render->offset_y = fabs(ray->z - floor(ray->z));
	else
		render->offset_y = fabs(ray->y - floor(ray->y));
}

void	set_pole(t_render *render, t_raycasting *rc, t_ray *ray, char **grid)
{
	if (rc->ray_dir_x > 0 && round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x] == '1')
		render->pole = EA;
	if (rc->ray_dir_y > 0 && round(ray->y) == ray->y
		&& grid[(int)ray->y][(int)ray->x] == '1')
		render->pole = SO;
	if (rc->ray_dir_x < 0 && round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x - 1] == '1')
		render->pole = WE;
	if (rc->ray_dir_y < 0 && round(ray->y) == ray->y
		&& grid[(int)ray->y - 1][(int)ray->x] == '1')
		render->pole = NO;
	if (rc->ray_dir_z > 0 && ray->z == HEIGHT)
		render->pole = TOP;
	if (rc->ray_dir_z < 0 && ray->z == 0)
		render->pole = BOT;
}

t_render	*get_render(t_ray *ray, char **grid, t_player *player)
{
	t_render		*render;
	t_raycasting	rc;

	set_collision(ray, grid, &rc);
	render = malloc(sizeof(t_render));
	if (!render)
		return (0);
	set_pole(render, &rc, ray, grid);
	set_offset(render, ray);
	render->distance = sqrt(pow(ray->z - HEIGT_PLAYER, 2) + pow(ray->x - player->pos.x, 2) + pow(ray->y - player->pos.y, 2));
	return (render);
}
