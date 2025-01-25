/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 04:31:58 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 19:12:29 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	exec(t_env *env)
{
	if (ft_mlx_init_win(env, env->mlx))
		return (env->err = ERR_MLX, 1);
	if (ft_mlx_init_events(env))
		return (env->err = ERR_MLX, 1);
	if (render_map_3d(env->map, env->mlx, env->textures))
		return (env->err = ERR_GAME, 1);
	mlx_loop_hook(env->mlx->id, loop_render, env);
	mlx_loop(env->mlx->id);
	return (0);
}
