/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:36:10 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 11:42:45 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_rgb_err(t_textures *textures)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		textures->rgb_ceiling[i] = -1;
		textures->rgb_floor[i] = -1;
		i++;
	}
}

short	init_env(t_env *env)
{
	env->gc = NULL;
	env->map = NULL;
	env->mlx = NULL;
	env->textures = NULL;
	env->gc = gc_init();
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
	env->event = malloc(sizeof(t_event));
	if (!env->event)
		return (1);
	ft_memset(env->event, 0, sizeof(t_event));
	set_rgb_err(env->textures);
	return (0);
}
