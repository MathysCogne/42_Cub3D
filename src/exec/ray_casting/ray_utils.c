/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:34:32 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/29 06:33:27 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
double	trigo_opposite_side(double angle, double len)
{
	return (len * tan(angle));
}