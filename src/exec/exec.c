/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 04:31:58 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/17 04:49:40 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

short	init_win_mlx(t_mlx *mlx)
{
	mlx->id = mlx_init();
	if (!mlx->id)
		return (1);
	mlx->win = mlx_new_window(mlx->id, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!mlx->win)
		return (1);
	return (0);
}

short	exec(t_env *env)
{
	if (init_win_mlx(env->mlx))
		return (1);
	// LOOP IN START GAME
	mlx_loop(env->mlx->id);
	return (0);
}