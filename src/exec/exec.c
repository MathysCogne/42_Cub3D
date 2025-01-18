/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 04:31:58 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/18 17:09:20 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	exec(t_env *env)
{
	if (ft_mlx_init_win(env->mlx))
		return (1);
	if (ft_mlx_init_events(env))
		return (1);
	render_map_2d(env->map, env->mlx);
	mlx_loop(env->mlx->id);
	return (0);
}
