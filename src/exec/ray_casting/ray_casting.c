/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:35:50 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/25 12:28:34 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	detroy_render(t_render **render)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < (WIN_WIDTH / 2))
		{
			free(render[((WIN_WIDTH / 2) * y) + x]);
			x++;
		}
		y++;
	}
	free(render);
}

t_render	*send_ray(int ray_index_v, int ray_index_h, t_player *player,
		char **grid)
{
	t_ray	ray;

	ray.angle_h = normalize_angle_h((player->pos.angle_h - (HFVH / 2)
				+ HFVH * (ray_index_h / (((double)WIN_WIDTH / 2) - 1))) * -1);
	ray.angle_v = (player->pos.angle_v - (HFVV / 2) + HFVV * (ray_index_v
				/ (((double)WIN_HEIGHT / 2) - 1))) * -1;
	ray.x = player->pos.y;
	ray.y = player->pos.x;
	ray.index = ray_index_v;
	ray.z = HEIGT_PLAYER;
	return (get_render(&ray, grid));
}

t_render	**ray_cast(t_player *player, char **grid)
{
	int			x;
	int			y;
	t_render	**render;

	render = malloc(sizeof(t_render) * (WIN_WIDTH / 2) * (WIN_HEIGHT / 2));
	if (!render)
		return (0);
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH / 2)
		{
			render[(WIN_WIDTH / 2 * y) + x] = send_ray(y, x, player, grid);
			if (!render[(WIN_WIDTH / 2 * y) + x])
				return (0);
			x++;
		}
		y++;
	}
	return (render);
}
