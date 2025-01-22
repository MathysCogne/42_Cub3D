/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:35:50 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/22 09:33:27 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

void	detroy_render(t_render **render)
{
	int			x;
	int			y;

	y = 0;
	while (y < (int)RESV)
	{
		x = 0;
		while (x < (int)RESH)
		{
			free(render[((int)RESH * y) + x]);
			x++;
		}
		y++;
	}
	free(render);
}

t_render	*send_ray(int ray_index_v, int ray_index_h, t_player *player, char **grid)
{
	t_ray	ray;

	ray.angle_h = normalize_angle(
			player->pos.angle_h - (HFVH / 2) + HFVH * (ray_index_h / (RESH - 1)));
	ray.angle_v = player->pos.angle_v - (HFVV / 2) + HFVV * (ray_index_v / (RESV - 1));
	ray.x = player->pos.x;
	ray.y = player->pos.y;
	ray.index = ray_index_v;
	ray.z = HEIGT_PLAYER;
	return (get_render(&ray, grid));
}

t_render	**ray_cast(t_player *player, char **grid)
{
	int			x;
	int			y;

	t_render **render = malloc(sizeof(t_render) * (int)RESH * (int)RESV);
	if (!render)
		return (0);
	y = 0;
	while (y < (int)RESV)
	{
		x = 0;
		while (x < (int)RESH)
		{
			render[((int)RESH * y) + x] = send_ray(y, x, player, grid);
			if (!render[((int)RESH * y) + x])
				return (0);
			x++;
		}
		y++;
	}
	return (render);
}
