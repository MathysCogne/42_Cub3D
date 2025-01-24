/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:41:29 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/24 18:43:41 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle_v(double angle)
{
	if (angle < -45)
		angle = -45;
	else if (angle >= 45)
		angle = 45;
	return (angle);
}

double	normalize_angle_h(double angle)
{
	if (angle < 0)
		angle += 360.0;
	else if (angle >= 360.0)
		angle -= 360.0;
	return (angle);
}
