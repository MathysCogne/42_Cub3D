/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:34:32 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/21 20:23:25 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_casting.h"

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += 360.0;
	else if (angle >= 360.0)
		angle -= 360.0;
	return (angle);
}

double	degree_to_radian(double degree)
{
	return (degree * (M_PI / 180.0));
}
