/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:40:26 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/16 02:08:24 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_parsing(t_env *env)
{
	if (DEBUG_MODE)
	{
		ft_printf(YELLOW "Param Map:\n" C_RESET);
		ft_printf("  NO -> %s\n", env->textures->no);
		ft_printf("  SO -> %s\n", env->textures->so);
		ft_printf("  WE -> %s\n", env->textures->we);
		ft_printf("  EA -> %s\n\n", env->textures->ea);
		ft_printf("  FL -> %s\n", env->textures->floor);
		ft_printf("  CE -> %s\n", env->textures->ceiling);
		ft_printf(YELLOW "\nMatrix Map:\n" C_RESET);
	}
}
