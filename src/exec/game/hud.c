/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:37:06 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/25 23:47:59 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	render_weapon(t_env *env)
{
	int		x;
	int		y;
	int		color;
	t_pos	pos;

	y = 0;
	while (y < env->textures->weapon.height)
	{
		x = 0;
		while (x < env->textures->weapon.width)
		{
			color = ft_get_pixel_color_hud(env->textures->weapon.value, x, y);
			pos.x = (WIN_WIDTH - env->textures->weapon.width) / 2 + x;
			pos.y = WIN_HEIGHT - env->textures->weapon.height + y;
			ft_put_pixel_in_img(env->mlx, pos, color);
			x++;
		}
		y++;
	}
	return (0);
}

short	handler_hud(t_env *env)
{
	handler_mini_map(env);
	render_weapon(env);
	return (0);
}