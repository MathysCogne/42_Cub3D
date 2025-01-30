/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:33:03 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 23:09:36 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	valid_rgb(t_textures *textures, int *rgb_floor,
		int *rgb_ceiling)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if ((rgb_floor[i] == NULL_RGB && !textures->path_bot)
			|| (rgb_ceiling[i] == NULL_RGB && !textures->path_top))
			return (1);
		if (rgb_floor[i] < MIN_RGB || rgb_floor[i] > MAX_RGB)
			return (1);
		if (rgb_ceiling[i] < MIN_RGB || rgb_ceiling[i] > MAX_RGB)
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
	if (valid_rgb(textures, textures->rgb_floor, textures->rgb_ceiling))
		return (1);
	return (0);
}
