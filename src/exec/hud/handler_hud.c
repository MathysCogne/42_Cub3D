/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:37:06 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/29 17:46:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	handler_hud(t_env *env)
{
	if (!env->event->menu_start || env->event->menu_died
		|| env->event->menu_happy_end)
		handler_menu(env);
	else
	{
		handler_mini_map(env);
		handler_waepon(env);
		handler_hud_stats_player(env);
		handler_put_strings(env);
		hud_bam_comics(env, 0);
	}
	return (0);
}
