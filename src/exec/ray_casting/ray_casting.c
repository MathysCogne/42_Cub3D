/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:35:50 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/26 14:43:13 by achaisne         ###   ########.fr       */
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

t_render	*send_ray(int ind_v, int ind_h, t_player *player, char **grid)
{
	t_ray	ray;

	ray.angle_h = normalize_angle_h((player->pos.angle_h - (HFVH / 2)
				+ HFVH * (ind_h / (((double)RESH) - 1))) * -1);
	ray.angle_v = (player->pos.angle_v - (HFVV / 2) + HFVV * (ind_v
				/ (((double)RESV) - 1))) * -1;
	ray.x = player->pos.y;
	ray.y = player->pos.x;
	ray.index = ind_v;
	ray.z = HEIGT_PLAYER;
	return (get_render(&ray, grid, player));
}

t_render	**ray_cast(t_player *player, char **grid)
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
			render[(RESH * y) + x] = send_ray(y, x, player, grid);
			if (!render[(RESH * y) + x])
				return (0);
			x++;
		}
		y++;
	}
	return (render);
}
