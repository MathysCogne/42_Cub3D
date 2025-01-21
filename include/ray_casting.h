/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:08:38 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/21 21:09:20 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>

# define RESH 1024.0
# define RESV 720.0
# define HFVH 90.0
# define HFVV 60.0
# define HEIGHT 1.0
# ifndef M_PI
#  define M_PI acos(-1.0)
# endif

#include "struct.h"

// raycasting
t_render	**ray_cast(t_player *player, char **grid);
// utils
double		degree_to_radian(double degree);
double		normalize_angle(double angle);
// ray render
t_render	*get_render(t_ray *ray, char **grid);
// ray setter
void		set_next_x(t_ray *ray, t_raycasting *raycasting);
void		set_next_y(t_ray *ray, t_raycasting *raycasting);
void		set_next_z(t_ray *ray, t_raycasting *raycasting);
void		set_ray(t_ray *ray, t_raycasting *raycasting);

#endif