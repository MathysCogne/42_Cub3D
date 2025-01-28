/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:13:35 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 21:37:46 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// INSERT ICI FT QUI RENVOIE 1 (ID DU MOB) SI LE TIR A TOUCHE ENNEMY
// POUR QUE JE METTE A JOUR LE MOB MORT

static short	piou_piou(t_env *env, t_map *map)
{
	(void)env;
	if (map->player.bullets > 0)
	{
		ft_printf(MINT_GREEN NAME "Piou Piou..\n");
		map->player.bullets--;
	}
	else
		ft_printf(MINT_GREEN NAME "No bullet in your weapon !\n");
	return (0);
}

short	handler_action_weapon(t_env *env)
{
	if (env->event->click_left)
		piou_piou(env, env->map);
	return (0);
}
