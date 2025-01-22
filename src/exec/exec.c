/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 04:31:58 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/22 01:16:03 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	exec(t_env *env)
{
	if (ft_mlx_init_win(env, env->mlx))
		return (env->err = ERR_MLX, 1);
	if (ft_mlx_init_events(env))
		return (env->err = ERR_MLX, 1);
	if (render_env_3d(env->map, env->mlx, env->textures))
		return (env->err = ERR_GAME, 1);
	if (render_map_2d(env->map, env->mlx))
		return (env->err = ERR_GAME, 1);
	mlx_loop(env->mlx->id);
	return (0);
}
