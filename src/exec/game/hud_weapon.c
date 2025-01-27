/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_weapon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:57:05 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 19:30:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*get_texture_weapon(t_env *env)
{
	if (env->event->click_left)
		return (env->textures->weapon_on.value);
	else
		return (env->textures->weapon_off.value);
}

static short	render_weapon(t_env *env)
{
	int		x;
	int		y;
	int		color;
	t_pos	pos;

	y = 0;
	while (y < env->textures->weapon_off.height)
	{
		x = 0;
		while (x < env->textures->weapon_off.width)
		{
			color = ft_get_pixel_color_hud(get_texture_weapon(env), x, y);
			if (color)
			{
				pos.x = (WIN_WIDTH - env->textures->weapon_off.width) / 2 + x;
				pos.y = WIN_HEIGHT - env->textures->weapon_off.height + y;
				ft_put_pixel_in_img(env->mlx, pos, color);
			}
			x++;
		}
		y++;
	}
	return (0);
}

short	handler_waepon(t_env *env)
{
	render_weapon(env);
	return (0);
}
