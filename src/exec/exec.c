/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 04:31:58 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 12:55:15 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	exec(t_env *env)
{
	if (ft_mlx_init_win(env, env->mlx))
		return (env->err = ERR_MLX, 1);
	if (ft_mlx_init_events(env))
		return (env->err = ERR_MLX, 1);
	mlx_loop_hook(env->mlx->id, loop_render, env);
	mlx_loop(env->mlx->id);
	return (0);
}
