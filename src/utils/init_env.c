/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:36:10 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/31 10:50:45 by achaisne         ###   ########.fr       */
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
	ft_memset(env, 0, sizeof(t_env));
	env->gc = gc_init();
	if (!env->gc)
		return (1);
	env->map = ft_calloc(sizeof(t_map), 1);
	if (!env->map)
		return (1);
	env->mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!env->mlx)
		return (1);
	env->textures = ft_calloc(sizeof(t_textures), 1);
	if (!env->textures)
		return (1);
	set_rgb_err(env->textures);
	env->event = ft_calloc(sizeof(t_event), 1);
	if (!env->event)
		return (1);
	return (0);
}
