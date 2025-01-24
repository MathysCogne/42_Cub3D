/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_setter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:22:00 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/24 17:48:46 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_next_x(t_ray *ray, t_raycasting *raycasting)
{
	if (raycasting->ray_dir_x > 0)
	{
		if (ray->x == ceil(ray->x))
			raycasting->next_x = ray->x + 1.0;
		else
			raycasting->next_x = ceil(ray->x);
	}
	else
	{
		if (ray->x == floor(ray->x))
			raycasting->next_x = ray->x - 1.0;
		else
			raycasting->next_x = floor(ray->x);
	}
}

void	set_next_y(t_ray *ray, t_raycasting *raycasting)
{
	if (raycasting->ray_dir_y > 0)
	{
		if (ray->y == ceil(ray->y))
			raycasting->next_y = ray->y + 1.0;
		else
			raycasting->next_y = ceil(ray->y);
	}
	else
	{
		if (ray->y == floor(ray->y))
			raycasting->next_y = ray->y - 1.0;
		else
			raycasting->next_y = floor(ray->y);
	}
}

void	set_next_z(t_ray *ray, t_raycasting *raycasting)
{
	if (raycasting->ray_dir_z > 0)
	{
		if (ray->z == ceil(ray->z))
			raycasting->next_z = ray->z + 1.0;
		else
			raycasting->next_z = ceil(ray->z);
	}
	else
	{
		if (ray->z == floor(ray->z))
			raycasting->next_z = ray->z - 1.0;
		else
			raycasting->next_z = floor(ray->z);
	}
}

void	set_ray(t_ray *ray, t_raycasting *raycasting)
{
	raycasting->side_dist_x
		= (raycasting->next_x - ray->x) / raycasting->ray_dir_x;
	raycasting->side_dist_y
		= (raycasting->next_y - ray->y) / raycasting->ray_dir_y;
	raycasting->side_dist_z
		= (raycasting->next_z - ray->z) / raycasting->ray_dir_z;
	if (raycasting->side_dist_y < raycasting->side_dist_x && raycasting->side_dist_y < raycasting->side_dist_z)
	{
		ray->x += (raycasting->next_y - ray->y)
			/ (raycasting->ray_dir_y / raycasting->ray_dir_x);
		ray->z += (raycasting->next_y - ray->y)
			/ (raycasting->ray_dir_y / raycasting->ray_dir_z);
		ray->y = raycasting->next_y;
	}
	else if (raycasting->side_dist_x < raycasting->side_dist_y && raycasting->side_dist_x < raycasting->side_dist_z)
	{
		ray->y += (raycasting->next_x - ray->x)
			/ (raycasting->ray_dir_x / raycasting->ray_dir_y);
		ray->z += (raycasting->next_x - ray->x)
			/ (raycasting->ray_dir_x / raycasting->ray_dir_z);
		ray->x = raycasting->next_x;
	}
	else
	{
		ray->x += (raycasting->next_z - ray->z)
			/ (raycasting->ray_dir_z / raycasting->ray_dir_x);
		ray->y += (raycasting->next_z - ray->z)
			/ (raycasting->ray_dir_z / raycasting->ray_dir_y);
		ray->z = raycasting->next_z;
	}
}
