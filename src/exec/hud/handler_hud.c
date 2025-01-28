/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:37:06 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 23:40:21 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	handler_hud(t_env *env)
{
	handler_mini_map(env);
	handler_waepon(env);
	handler_hud_stats_player(env);
	handler_put_strings(env);
	return (0);
}
