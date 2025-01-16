/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:36:10 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/16 00:18:32 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	init_env(t_env *env)
{
	env->gc = NULL;
	env->gc = gc_init();
	env->map = NULL;
	env->mlx = NULL;
	env->textures = NULL;
	if (!env->gc)
		return (1);
	env->map = malloc(sizeof(t_map));
	if (!env->map)
		return (1);
	ft_memset(env->map, 0, sizeof(t_map));
	env->mlx = malloc(sizeof(t_mlx));
	if (!env->mlx)
		return (1);
	ft_memset(env->mlx, 0, sizeof(t_mlx));
	env->textures = malloc(sizeof(t_textures));
	if (!env->textures)
		return (1);
	ft_memset(env->textures, 0, sizeof(t_textures));
	return (0);
}
