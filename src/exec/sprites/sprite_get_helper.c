/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_get_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:27:51 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 18:32:18 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_texture(char c, t_textures *textures, t_map *map)
{
	if (c == '2')
		return (&textures->monster[get_id_monsters(map)]);
	if (c == '3')
		return (&textures->musk[get_id_musk(map)]);
	return (0);
}

int	normalize_width(int img_width)
{
	return (RESH * img_width / 540);
}

int	normalize_height(int img_height)
{
	return (RESV * img_height / 360);
}
