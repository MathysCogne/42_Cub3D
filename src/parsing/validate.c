/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:44:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/19 18:34:15 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static short	valid_datat(t_map *map)
// {
// 	return (0);
// }

// static short	valid_close_wall(t_map *map)
// {
// 	return (0);
// }

static short	valid_carac(t_map *map)
{
	size_t	i;
	short	is_data_part;

	i = 0;
	is_data_part = 1;
	while (map->file[i])
	{
		ft_printf(RED "%c" C_RESET, map->file[i]);
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

short	handler_validate_parsing(t_env *env, t_map *map)
{
	(void)env;
	if (valid_carac(map))
		return (env->err = ERR_PARSE_CARAC, 1);
	// if (valid_close_wall(map))
	// 	return (1);
	// if (valid_data(map))
	// 	return (1);
	// if (valid_data_before_map(map))
	// 	return (1);
	return (0);
}