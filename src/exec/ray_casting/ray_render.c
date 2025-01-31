/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:45:34 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/31 10:00:13 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_offset(t_render *render, t_ray *ray, t_textures *textures)
{
	if (render->texture != &textures->ea
		&& render->texture != &textures->we
		&& render->texture != &textures->door_ea
		&& render->texture != &textures->door_we)
		render->offset_x = fabs(ray->x - floor(ray->x));
	else
		render->offset_x = fabs(ray->y - floor(ray->y));
	if (render->texture != &textures->bot
		&& render->texture != &textures->top
		&& render->texture != &textures->bot_blood)
		render->offset_y = fabs(ray->z - floor(ray->z));
	else
		render->offset_y = fabs(ray->y - floor(ray->y));
}

void	set_texture(t_render *render, t_raycasting *rc,
						char **grid, t_textures *textures)
{
	set_texture_classic(render, rc, grid, textures);
	if (render->texture == 0)
		set_texture_door(render, rc, grid, textures);
}

void	set_distance(t_player *player, t_render *render, t_ray *ray)
{
	render->distance = sqrt(
			pow(ray->z - HEIGT_PLAYER, 2)
			+ pow(ray->x - player->pos.x, 2)
			+ pow(ray->y - player->pos.y, 2));
}

t_render	*get_render(t_player *player, t_raycasting *rc,
							char **grid, t_textures *textures)
{
	t_render		*render;

	render = ft_calloc(sizeof(t_render), 1);
	if (!render)
		return (0);
	set_texture(render, rc, grid, textures);
	set_offset(render, &rc->ray, textures);
	set_distance(player, render, &rc->ray);
	return (render);
}
