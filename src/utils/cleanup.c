/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:06:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/29 11:03:17 by achaisne         ###   ########.fr       */
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
