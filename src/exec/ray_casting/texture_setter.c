/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 05:11:33 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/28 05:35:24 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_door(t_render *render, t_raycasting *rc, char **grid)
{
	if (rc->ray_dir_x > 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '9')
		render->pole = DOOR_EA;
	else if (rc->ray_dir_y > 0 && round(rc->ray.y) == rc->ray.y
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '9')
		render->pole = DOOR_SN;
	else if (rc->ray_dir_x < 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x - 1] == '9')
		render->pole = DOOR_WE;
	else if (rc->ray_dir_y < 0 && round(rc->ray.y) == rc->ray.y && grid[(int)rc->ray.y
		- 1][(int)rc->ray.x] == '9')
		render->pole = DOOR_SN;
}

void	set_texture_classic(t_render *render, t_raycasting *rc,	char **grid)
{
	if (rc->ray_dir_x > 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '1')
		render->pole = EA;
	else if (rc->ray_dir_y > 0 && round(rc->ray.y) == rc->ray.y
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '1')
		render->pole = SO;
	else if (rc->ray_dir_x < 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x - 1] == '1')
		render->pole = WE;
	else if (rc->ray_dir_y < 0 && round(rc->ray.y) == rc->ray.y && grid[(int)rc->ray.y
		- 1][(int)rc->ray.x] == '1')
		render->pole = NO;
	else if (rc->ray_dir_z > 0 && rc->ray.z == HEIGHT)
		render->pole = TOP;
	else if (rc->ray_dir_z < 0 && rc->ray.z == 0)
		render->pole = BOT;
}
