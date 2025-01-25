/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_setter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:22:00 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/25 13:55:56 by achaisne         ###   ########.fr       */
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

void	set_ray(t_ray *ray, t_raycasting *rc)
{
	rc->side_dist_x = (rc->next_x - ray->x) / rc->ray_dir_x;
	rc->side_dist_y = (rc->next_y - ray->y) / rc->ray_dir_y;
	rc->side_dist_z = (rc->next_z - ray->z) / rc->ray_dir_z;
	if (rc->side_dist_y < rc->side_dist_x
		&& rc->side_dist_y < rc->side_dist_z)
	{
		ray->x += rc->ray_dir_x * (rc->next_y - ray->y) / rc->ray_dir_y;
		ray->z += rc->ray_dir_z * (rc->next_y - ray->y) / rc->ray_dir_y;
		ray->y = rc->next_y;
	}
	else if (rc->side_dist_x < rc->side_dist_y
		&& rc->side_dist_x < rc->side_dist_z)
	{
		ray->y += rc->ray_dir_y * (rc->next_x - ray->x) / rc->ray_dir_x;
		ray->z += rc->ray_dir_z * (rc->next_x - ray->x) / rc->ray_dir_x;
		ray->x = rc->next_x;
	}
	else
	{
		ray->x += rc->ray_dir_x * (rc->next_z - ray->z) / rc->ray_dir_z;
		ray->y += rc->ray_dir_y * (rc->next_z - ray->z) / rc->ray_dir_z;
		ray->z = rc->next_z;
	}
}
