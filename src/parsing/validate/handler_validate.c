/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:44:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 17:40:27 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	handler_validate_parsing(t_env *env, t_map *map)
{
	if (valid_carac(map))
		return (env->err = ERR_PARSE_CARAC, 1);
	if (valid_close_wall(map, map->grid))
		return (env->err = ERR_PARSE_WALL, 1);
	if (valid_player(map, map->grid))
		return (env->err = ERR_PARSE_PLAYER, 1);
	if (handler_valid_data(env, env->textures))
		return (env->err = ERR_PARSE_DATA, 1);
	if (valid_door(map, map->grid))
		return (env->err = ERR_PARSE_DOOR, 1);
	return (0);
}
