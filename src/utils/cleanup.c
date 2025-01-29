/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:06:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/29 16:44:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_mlx_destroy_image(t_env *env, void *ptr)
{
	if (ptr)
	{
		mlx_destroy_image(env->mlx->id, ptr);
		ptr = NULL;
	}
}

static void	cleanup_textures(t_env *env)
{
	if (env->textures)
	{
		ft_free(env->textures->path_no);
		ft_free(env->textures->path_so);
		ft_free(env->textures->path_we);
		ft_free(env->textures->path_ea);
		ft_free(env->textures->path_bot);
		ft_free(env->textures->path_top);
		ft_mlx_destroy_image(env, env->textures->no.value);
		ft_mlx_destroy_image(env, env->textures->so.value);
		ft_mlx_destroy_image(env, env->textures->we.value);
		ft_mlx_destroy_image(env, env->textures->ea.value);
		ft_mlx_destroy_image(env, env->textures->bot.value);
		ft_mlx_destroy_image(env, env->textures->top.value);
		ft_mlx_destroy_image(env, env->textures->door_ea.value);
		ft_mlx_destroy_image(env, env->textures->door_we.value);
		ft_mlx_destroy_image(env, env->textures->door_so.value);
		ft_mlx_destroy_image(env, env->textures->door_no.value);
		ft_mlx_destroy_image(env, env->textures->weapon_off.value);
		ft_mlx_destroy_image(env, env->textures->weapon_on.value);
		ft_mlx_destroy_image(env, env->textures->hud_border_map.value);
		ft_mlx_destroy_image(env, env->textures->hud_card_id.value);
		ft_mlx_destroy_image(env, env->textures->hud_pv.value);
		ft_mlx_destroy_image(env, env->textures->hud_pv_rod.value);
		ft_mlx_destroy_image(env, env->textures->hud_stamina.value);
		ft_mlx_destroy_image(env, env->textures->hud_stamina_rod.value);
		ft_mlx_destroy_image(env, env->textures->hud_bam.value);
		ft_mlx_destroy_image(env, env->textures->musk[0].value);
		ft_mlx_destroy_image(env, env->textures->musk[1].value);
		ft_mlx_destroy_image(env, env->textures->musk[2].value);
		ft_mlx_destroy_image(env, env->textures->musk[3].value);
		ft_mlx_destroy_image(env, env->textures->monster[0].value);
		ft_mlx_destroy_image(env, env->textures->monster[1].value);
		ft_mlx_destroy_image(env, env->textures->monster[2].value);
		ft_mlx_destroy_image(env, env->textures->monster[3].value);
		ft_mlx_destroy_image(env, env->textures->monster[4].value);
		ft_mlx_destroy_image(env, env->textures->menu_start.value);
		ft_mlx_destroy_image(env, env->textures->menu_end.value);
		ft_mlx_destroy_image(env, env->mlx->render_pixel);
		ft_free(env->textures);
	}
}

static void	cleanup_mlx(t_env *env)
{
	if (env->mlx)
	{
		if (env->mlx->id && env->mlx->win)
		{
			mlx_destroy_window(env->mlx->id, env->mlx->win);
			mlx_destroy_display(env->mlx->id);
		}
		ft_free(env->mlx->id);
		ft_free(env->mlx);
	}
}

static void	cleanup_map(t_env *env)
{
	if (env->map)
	{
		ft_free(env->map->file);
		ft_free(env->map->grid);
		ft_free(env->map);
	}
}

void	cleanup(t_env *env)
{
	if (env->gc)
		gc_clean(env->gc);
	cleanup_map(env);
	cleanup_textures(env);
	cleanup_mlx(env);
	ft_free(env->event);
}
