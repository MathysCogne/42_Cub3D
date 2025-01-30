/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:27:27 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 22:27:55 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	valid_textures(t_textures *textures)
{
	if (!textures->ea.value || !textures->no.value || !textures->so.value
		|| !textures->we.value || !textures->bot_blood.value)
		return (1);
	if ((textures->rgb_floor[0] == -1 && !textures->bot.value)
		|| (textures->rgb_ceiling[0] == -1 && !textures->top.value))
		return (1);
	if (!textures->weapon_off.value || !textures->weapon_on.value
		|| !textures->door_ea.value || !textures->door_we.value
		|| !textures->door_so.value || !textures->door_no.value)
		return (1);
	if (!textures->hud_border_map.value || !textures->hud_card_id.value
		|| !textures->hud_pv.value || !textures->hud_pv_rod.value
		|| !textures->hud_stamina.value || !textures->hud_stamina_rod.value
		|| !textures->menu_start.value || !textures->menu_end.value
		|| !textures->menu_happy_end.value || !textures->hud_bam.value)
		return (1);
	if (!textures->monster[0].value || !textures->monster[1].value
		|| !textures->monster[2].value || !textures->monster[3].value)
		return (1);
	if (!textures->musk[0].value || !textures->musk[1].value
		|| !textures->musk[2].value || !textures->musk[3].value
		|| !textures->musk[4].value)
		return (1);
	return (0);
}
