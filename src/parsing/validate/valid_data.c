/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:33:03 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/20 21:44:53 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	valid_rgb(int *rgb_floor, int *rgb_ceiling)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (rgb_floor[i] == -1 || rgb_ceiling[i] == -1)
			return (1);
		if (rgb_floor[i] < 0 || rgb_floor[i] > 255)
			return (1);
		if (rgb_ceiling[i] < 0 || rgb_ceiling[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

static short	is_null_path_rgb(t_textures *textures)
{
	if (!textures->path_ea || !textures->path_no || !textures->path_so
		|| !textures->path_we || !*textures->rgb_ceiling
		|| !*textures->rgb_floor)
		return (1);
	return (0);
}

short	handler_valid_data(t_env *env, t_textures *textures)
{
	(void)env;
	if (is_null_path_rgb(textures))
		return (1);
	if (valid_rgb(textures->rgb_floor, textures->rgb_ceiling))
		return (1);
	return (0);
}
