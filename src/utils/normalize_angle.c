/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dwa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:41:29 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 17:43:06 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle_vertical(double angle)
{
	if (angle < 0)
		angle += 35;
	else if (angle >= 35)
		angle -= 35;
	return (angle);
}

double	normalize_angle_horizontal(double angle)
{
	if (angle < 0)
		angle += 360.0;
	else if (angle >= 360.0)
		angle -= 360.0;
	return (angle);
}
