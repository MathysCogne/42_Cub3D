/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:05:17 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 08:15:10 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_superior(int a, int b)
{
	return (a > b);
}

int	is_inferior(int a, int b)
{
	return (a < b);
}

double	degree_to_radian(double degree)
{
	return (degree * (M_PI / 180.0));
}

/**
 * Triangle ABC, BCA 90°
 *
 * angle: CAB (in radian)
 * len: AC
 * return: BC len
 */
double	trigo_get_opposite_len(double angle, double len)
{
	return (len * tan(angle));
}

double	trigo_get_hypotenuse_len(double sprite_dy, double sprite_dx)
{
	return (sqrt(sprite_dx * sprite_dx + sprite_dy * sprite_dy));
}

double	trigo_get_angle(double sprite_dy, double sprite_dx)
{
	return atan2(sprite_dy, sprite_dx);
}