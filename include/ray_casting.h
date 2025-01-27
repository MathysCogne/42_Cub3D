/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:08:38 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/26 16:10:39 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include "struct.h"

# define HFVH 90.0
# define HFVV 60.0
# define HEIGHT 1.0
# define HEIGT_PLAYER 0.5

# define WALL_DOOR "19"

// raycasting
void		detroy_render(t_render **render);
t_render	**ray_cast(t_player *player, char **grid);
// utils
double		degree_to_radian(double degree);
// ray render
t_render	*get_render(t_ray *ray, char **grid, t_player *player);
// ray setter
void		set_next_x(t_ray *ray, t_raycasting *raycasting);
void		set_next_y(t_ray *ray, t_raycasting *raycasting);
void		set_next_z(t_ray *ray, t_raycasting *raycasting);
void		set_ray(t_ray *ray, t_raycasting *raycasting);

#endif