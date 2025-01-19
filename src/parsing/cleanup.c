/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:06:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/19 23:32:48 by mcogne--         ###   ########.fr       */
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
		ft_mlx_destroy_image(env, env->textures->t_no);
		ft_mlx_destroy_image(env, env->textures->t_so);
		ft_mlx_destroy_image(env, env->textures->t_we);
		ft_mlx_destroy_image(env, env->textures->t_ea);
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
}
