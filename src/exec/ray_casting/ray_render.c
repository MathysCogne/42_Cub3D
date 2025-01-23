/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:45:34 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/23 16:46:25 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

int	is_collision(t_ray *ray, t_raycasting *collision, char **grid)
{
	if (collision->ray_dir_x > 0
		&& round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x] == '1')
		return (1);
	if (collision->ray_dir_y > 0
		&& round(ray->y) == ray->y
		&& grid[(int)ray->y][(int)ray->x] == '1')
		return (1);
	if (collision->ray_dir_x < 0
		&& round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x - 1] == '1')
		return (1);
	if (collision->ray_dir_y < 0
		&& round(ray->y) == ray->y
		&& grid[(int)ray->y - 1][(int)ray->x] == '1')
		return (1);
	if (collision->ray_dir_z > 0 && ray->z == HEIGHT)
		return (1);
	if (collision->ray_dir_z < 0 && ray->z == 0)
		return (1);
	return (0);
}

void	set_collision(t_ray *ray, char **grid, t_raycasting *collision)
{
	collision->ray_dir_x = cos(degree_to_radian(ray->angle_h));
	if (collision->ray_dir_x == 0)
		collision->ray_dir_x += 1e-9;
	collision->ray_dir_y = sin(degree_to_radian(ray->angle_h));
	if (collision->ray_dir_y == 0)
		collision->ray_dir_y += 1e-9;
	collision->ray_dir_z = sin(degree_to_radian(ray->angle_v));
	if (collision->ray_dir_z == 0)
		collision->ray_dir_z += 1e-9;
	while (!is_collision(ray, collision, grid))
	{
		set_next_x(ray, collision);
		set_next_y(ray, collision);
		set_next_z(ray, collision);
		set_ray(ray, collision);
	}
}

t_render	*get_render(t_ray *ray, char **grid)
{
	t_render	*render;
	t_raycasting collision;

	set_collision(ray, grid, &collision);
	render = malloc(sizeof(t_render));
	if (!render)
		return (0);
	if (collision.ray_dir_x > 0
		&& round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x] == '1')
		render->pole = EA;
	if (collision.ray_dir_y > 0
		&& round(ray->y) == ray->y
		&& grid[(int)ray->y][(int)ray->x] == '1')
		render->pole = SO;
	if (collision.ray_dir_x < 0
		&& round(ray->x) == ray->x
		&& grid[(int)ray->y][(int)ray->x - 1] == '1')
		render->pole = WE;
	if (collision.ray_dir_y < 0
		&& round(ray->y) == ray->y
		&& grid[(int)ray->y - 1][(int)ray->x] == '1')
		render->pole = NO;
	if (collision.ray_dir_z > 0 && ray->z == HEIGHT)
		render->pole = TOP;
	if (collision.ray_dir_z < 0 && ray->z == 0)
		render->pole = BOT;
	if (render->pole != EA && render->pole != WE)
		render->offset_x = fabs(ray->x - floor(ray->x));
	else
		render->offset_x = fabs(ray->y - floor(ray->y));
	if (render->pole != BOT && render->pole != TOP)
		render->offset_y = fabs(ray->z - floor(ray->z));
	else
		render->offset_y = fabs(ray->y - floor(ray->y));
	return (render);
}