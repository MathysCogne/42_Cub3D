/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:06:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 08:53:02 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cleanup_textures_2(t_env *env)
{
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
	ft_mlx_destroy_image(env, env->textures->musk[4].value);
	ft_mlx_destroy_image(env, env->textures->monster[0].value);
	ft_mlx_destroy_image(env, env->textures->monster[1].value);
	ft_mlx_destroy_image(env, env->textures->monster[2].value);
	ft_mlx_destroy_image(env, env->textures->monster[3].value);
	ft_mlx_destroy_image(env, env->textures->menu_start.value);
	ft_mlx_destroy_image(env, env->textures->menu_end.value);
	ft_mlx_destroy_image(env, env->textures->menu_happy_end.value);
	ft_mlx_destroy_image(env, env->mlx->render_pixel);
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
		ft_mlx_destroy_image(env, env->textures->bot_blood.value);
		ft_mlx_destroy_image(env, env->textures->top.value);
		ft_mlx_destroy_image(env, env->textures->door_ea.value);
		ft_mlx_destroy_image(env, env->textures->door_we.value);
		ft_mlx_destroy_image(env, env->textures->door_so.value);
		ft_mlx_destroy_image(env, env->textures->door_no.value);
		ft_mlx_destroy_image(env, env->textures->weapon_off.value);
		ft_mlx_destroy_image(env, env->textures->weapon_on.value);
		cleanup_textures_2(env);
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
	pthread_mutex_destroy(&env->map->mutex_sprite);
	cleanup_map(env);
	cleanup_textures(env);
	cleanup_mlx(env);
	ft_free(env->event);
}
