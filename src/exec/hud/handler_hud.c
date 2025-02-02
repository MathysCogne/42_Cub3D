/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:37:06 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:05:02 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handler_hud(t_env *env)
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
}
