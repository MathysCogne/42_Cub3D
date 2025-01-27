/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_msg_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:34:44 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 17:41:14 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_msg_error(size_t err)
{
	if (!err)
		return ("An unexpected error occurred.");
	if (err == ERR_INIT_ENV)
		return ("Error initializing data structures.");
	if (err == ERR_PARSE_READ)
		return ("Error occurred while read the file map.");
	if (err == ERR_PARSE_PROCESS)
		return ("Error occurred while loading the map.");
	if (err == ERR_PARSE_CARAC)
		return ("Invalid Map: Incorrect character.");
	if (err == ERR_PARSE_WALL)
		return ("Invalid Map: Map is not enclosed by walls.");
	if (err == ERR_PARSE_DATA)
		return ("Error occurred while loading data (RGB or Path Textures).");
	if (err == ERR_PARSE_PLAYER)
		return ("Invalid Map: No or more than one players present in the map.");
	if (err == ERR_PARSE_DOOR)
		return ("Invalid Map: Door is not enclosed by walls.");
	if (err == ERR_MLX)
		return ("Error occurred while mlx functions core.");
	if (err == ERR_GAME)
		return ("Error occurred during the game process.");
	return ("An unexpected error occurred.");
}
