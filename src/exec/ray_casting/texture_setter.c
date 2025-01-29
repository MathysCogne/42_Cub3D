/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 05:11:33 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 17:04:14 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_door(t_render *render, t_raycasting *rc,
							char **grid, t_textures *textures)
{
	if (rc->ray_dir_x > 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '9')
		render->texture = &textures->door_ea;
	else if (rc->ray_dir_y > 0 && round(rc->ray.y) == rc->ray.y
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '9')
		render->texture = &textures->door_so;
	else if (rc->ray_dir_x < 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x - 1] == '9')
		render->texture = &textures->door_we;
	else if (rc->ray_dir_y < 0 && round(rc->ray.y) == rc->ray.y
		&& grid[(int)rc->ray.y - 1][(int)rc->ray.x] == '9')
		render->texture = &textures->door_no;
}

void	set_texture_classic(t_render *render, t_raycasting *rc,
								char **grid, t_textures *textures)
{
	if (rc->ray_dir_x > 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '1')
		render->texture = &textures->ea;
	else if (rc->ray_dir_y > 0 && round(rc->ray.y) == rc->ray.y
		&& grid[(int)rc->ray.y][(int)rc->ray.x] == '1')
		render->texture = &textures->so;
	else if (rc->ray_dir_x < 0 && round(rc->ray.x) == rc->ray.x
		&& grid[(int)rc->ray.y][(int)rc->ray.x - 1] == '1')
		render->texture = &textures->we;
	else if (rc->ray_dir_y < 0 && round(rc->ray.y) == rc->ray.y
		&& grid[(int)rc->ray.y - 1][(int)rc->ray.x] == '1')
		render->texture = &textures->no;
	else if (rc->ray_dir_z > 0 && rc->ray.z == HEIGHT)
		render->texture = &textures->top;
	else if (rc->ray_dir_z < 0 && rc->ray.z == 0)
	{
		if (grid[(int)rc->ray.y][(int)rc->ray.x] == '4')
			render->texture = &textures->bot_blood;
		else
			render->texture = &textures->bot;
	}
}
