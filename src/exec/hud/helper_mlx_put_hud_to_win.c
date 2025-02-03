/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_mlx_put_hud_to_win.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:01:44 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:15:57 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	helper_mlx_put_height_start_hud_to_win(t_env *env, t_texture texture,
		t_pos pos, int height_start)
{
	int		x;
	int		y;
	int		color;
	t_pos	pos_p;

	y = ft_abs(height_start - texture.height);
	while (y < texture.height)
	{
		x = 0;
		while (x < texture.width)
		{
			color = ft_get_pixel_color_hud(texture.value, x, y);
			if (color && color != HEX_BG_MAP)
			{
				pos_p.x = pos.x + x;
				pos_p.y = pos.y + y;
				ft_put_pixel_in_img(env->mlx, pos_p, color);
			}
			x++;
		}
		y++;
	}
}

void	helper_mlx_put_width_max_hud_to_win(t_env *env, t_texture texture,
		t_pos pos, int width_max)
{
	int		x;
	int		y;
	int		color;
	t_pos	pos_p;

	y = 0;
	while (y < texture.height)
	{
		x = 0;
		while (x < texture.width && x < width_max)
		{
			color = ft_get_pixel_color_hud(texture.value, x, y);
			if (color && color != HEX_BG_MAP)
			{
				pos_p.x = pos.x + x;
				pos_p.y = pos.y + y;
				ft_put_pixel_in_img(env->mlx, pos_p, color);
			}
			x++;
		}
		y++;
	}
}

void	helper_mlx_put_hud_to_win(t_env *env, t_texture texture, t_pos pos)
{
	int		x;
	int		y;
	int		color;
	t_pos	pos_p;

	y = 0;
	while (y < texture.height)
	{
		x = 0;
		while (x < texture.width)
		{
			color = ft_get_pixel_color_hud(texture.value, x, y);
			pos_p.x = pos.x + x;
			pos_p.y = pos.y + y;
			if (!env->event->menu_start || env->event->menu_died)
				ft_put_pixel_in_img(env->mlx, pos_p, color);
			else if (color && color != HEX_BG_MAP)
				ft_put_pixel_in_img(env->mlx, pos_p, color);
			x++;
		}
		y++;
	}
}
