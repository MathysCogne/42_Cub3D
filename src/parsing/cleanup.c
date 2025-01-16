/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:06:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/16 00:33:22 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cleanup_textures(t_env *env)
{
	if (env->textures)
	{
		ft_free(env->textures->no);
		ft_free(env->textures->so);
		ft_free(env->textures->we);
		ft_free(env->textures->ea);
		ft_free(env->textures->floor);
		ft_free(env->textures->ceiling);
		ft_free(env->textures);
	}
}

static void	cleanup_mlx(t_env *env)
{
	if (env->mlx)
	{
		if (env->mlx->id && env->mlx->win)
			mlx_destroy_window(env->mlx->id, env->mlx->win);
		ft_free(env->mlx->id);
		ft_free(env->mlx);
	}
}

static void	cleanup_map(t_env *env)
{
	if (env->map)
	{
		ft_free(env->map->file);
		ft_free(env->map->map);
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
