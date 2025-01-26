/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:01:24 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/26 04:43:53 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_prite
{
	double	x;
	double	y;
	double	offsetx;
	double	offsetz;
	double	distance;
	int		sprite_height;
	int		sprite_width;
}	t_sprite;


double	get_sprite_distance(t_player *player, double sprite_dy, double sprite_dx)
{
	float distance = sqrt(sprite_dx * sprite_dx + sprite_dy * sprite_dy);
}

double	get_sprite_angle(t_player *player, double sprite_dy, double sprite_dx)
{
	return atan2(sprite_dy, sprite_dx);
}

void	set_sprite(t_player *player, t_sprite *sprite)
{
	float sprite_dx;
	float sprite_dy;
	
	sprite_dy = sprite->y - player->pos.y;
	sprite_dx = sprite->x - player->pos.x;

	float angle_diff = get_sprite_angle(player, sprite_dy, sprite_dx) - player->pos.angle_h;
	if (angle_diff > M_PI)
		angle_diff -= 2 * M_PI;
	if (angle_diff < -M_PI)
		angle_diff += 2 * M_PI;

	if (fabs(angle_diff) > HFVH / 2)
		return (0); // TRUE

	float inv_det = 1.0 / (player->plane_x * player->dir_y - player->dir_x * player->plane_y);
	float transform_x = inv_det * (player->dir_y * sprite_dx - player->dir_x * sprite_dy);
	float transform_y = inv_det * (-player->plane_y * sprite_dx + player->plane_x * sprite_dy);

	sprite->distance = get_sprite_distance(player, sprite_dy, sprite_dx); // TRUE
	sprite->offsetx = (int)((WIN_WIDTH / 2) * (1 + transform_x / transform_y));
	sprite->sprite_height =  (int)(WIN_HEIGHT / sprite->distance); // TRUE
	sprite->sprite_width =  (int)(WIN_WIDTH / sprite->distance); // TRUE
}