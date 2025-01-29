/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:45:34 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 08:38:43 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_offset(t_render *render, t_ray *ray)
{
	if (render->pole != EA && render->pole != WE && render->pole != DOOR_EA
		&& render->pole != DOOR_WE)
		render->offset_x = fabs(ray->x - floor(ray->x));
	else
		render->offset_x = fabs(ray->y - floor(ray->y));
	if (render->pole != BOT && render->pole != TOP && render->pole != BOT_BLOOD)
		render->offset_y = fabs(ray->z - floor(ray->z));
	else
		render->offset_y = fabs(ray->y - floor(ray->y));
}

void	set_texture(t_render *render, t_raycasting *rc, char **grid)
{
	set_texture_classic(render, rc, grid);
	if (render->pole == NONE)
		set_texture_door(render, rc, grid);
}

void	set_distance(t_player *player, t_render *render, t_ray *ray)
{
	render->distance = sqrt(
			pow(ray->z - HEIGT_PLAYER, 2)
			+ pow(ray->x - player->pos.x, 2)
			+ pow(ray->y - player->pos.y, 2));
}

t_render	*get_render(t_player *player, t_raycasting *rc, char **grid)
{
	t_render		*render;

	render = calloc(sizeof(t_render), 1);
	if (!render)
		return (0);
	set_texture(render, rc, grid);
	set_offset(render, &rc->ray);
	set_distance(player, render, &rc->ray);
	return (render);
}
