/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_carac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:29:09 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/20 20:29:26 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	valid_carac(t_map *map)
{
	size_t	i;
	short	is_data_part;

	i = 0;
	is_data_part = 1;
	while (map->file[i])
	{
		if (is_texture_line(&map->file[i]) && is_data_part)
		{
			while (map->file[i] && map->file[i] != '\n')
				i++;
		}
		else if (!is_texture_line(&map->file[i]) && map->file[i] != '\n')
			is_data_part = 0;
		if (!ft_strchr(CARAC_MAP, map->file[i]) && map->file[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
