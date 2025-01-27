/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:40:26 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 15:38:53 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_print_rgb(char *type, int *rgb)
{
	ft_printf("  %s -> %d %d %d\n", type, rgb[0], rgb[1], rgb[2]);
}

static void	debug_matrix_map(t_map *map)
{
	size_t	i;

	i = 0;
	ft_printf(YELLOW "\nMatrix Map:\n" C_RESET);
	while (i < map->height)
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
}

void	debug_parsing(t_env *env)
{
	if (DEBUG_MODE)
	{
		ft_printf(YELLOW "Param Map:\n" C_RESET);
		ft_printf("  NO -> %s\n", env->textures->path_no);
		ft_printf("  SO -> %s\n", env->textures->path_so);
		ft_printf("  WE -> %s\n", env->textures->path_we);
		ft_printf("  EA -> %s\n\n", env->textures->path_ea);
		ft_printf("  FL -> %s\n", env->textures->path_bot);
		ft_printf("  CE -> %s\n", env->textures->path_top);
		debug_print_rgb("FL", env->textures->rgb_floor);
		debug_print_rgb("CE", env->textures->rgb_ceiling);
		debug_matrix_map(env->map);
	}
}
