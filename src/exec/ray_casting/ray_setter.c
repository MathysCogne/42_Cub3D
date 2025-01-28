/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_setter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:22:00 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/28 05:38:17 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_next_x(t_raycasting *rc)
{
	if (rc->ray_dir_x > 0)
	{
		if (rc->ray.x == ceil(rc->ray.x))
			rc->next_x = rc->ray.x + 1.0;
		else
			rc->next_x = ceil(rc->ray.x);
	}
	else
	{
		if (rc->ray.x == floor(rc->ray.x))
			rc->next_x = rc->ray.x - 1.0;
		else
			rc->next_x = floor(rc->ray.x);
	}
}

void	set_next_y(t_raycasting *rc)
{
	if (rc->ray_dir_y > 0)
	{
		if (rc->ray.y == ceil(rc->ray.y))
			rc->next_y = rc->ray.y + 1.0;
		else
			rc->next_y = ceil(rc->ray.y);
	}
	else
	{
		if (rc->ray.y == floor(rc->ray.y))
			rc->next_y = rc->ray.y - 1.0;
		else
			rc->next_y = floor(rc->ray.y);
	}
}

void	set_next_z(t_raycasting *rc)
{
	if (rc->ray_dir_z > 0)
	{
		if (rc->ray.z == ceil(rc->ray.z))
			rc->next_z = rc->ray.z + 1.0;
		else
			rc->next_z = ceil(rc->ray.z);
	}
	else
	{
		if (rc->ray.z == floor(rc->ray.z))
			rc->next_z = rc->ray.z - 1.0;
		else
			rc->next_z = floor(rc->ray.z);
	}
}

void	set_ray(t_raycasting *rc)
{
	rc->side_dist_x = (rc->next_x - rc->ray.x) / rc->ray_dir_x;
	rc->side_dist_y = (rc->next_y - rc->ray.y) / rc->ray_dir_y;
	rc->side_dist_z = (rc->next_z - rc->ray.z) / rc->ray_dir_z;
	if (rc->side_dist_y < rc->side_dist_x
		&& rc->side_dist_y < rc->side_dist_z)
	{
		rc->ray.x += rc->ray_dir_x * (rc->next_y - rc->ray.y) / rc->ray_dir_y;
		rc->ray.z += rc->ray_dir_z * (rc->next_y - rc->ray.y) / rc->ray_dir_y;
		rc->ray.y = rc->next_y;
	}
	else if (rc->side_dist_x < rc->side_dist_y
		&& rc->side_dist_x < rc->side_dist_z)
	{
		rc->ray.y += rc->ray_dir_y * (rc->next_x - rc->ray.x) / rc->ray_dir_x;
		rc->ray.z += rc->ray_dir_z * (rc->next_x - rc->ray.x) / rc->ray_dir_x;
		rc->ray.x = rc->next_x;
	}
	else
	{
		rc->ray.x += rc->ray_dir_x * (rc->next_z - rc->ray.z) / rc->ray_dir_z;
		rc->ray.y += rc->ray_dir_y * (rc->next_z - rc->ray.z) / rc->ray_dir_z;
		rc->ray.z = rc->next_z;
	}
}
