/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:08:38 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/30 17:20:58 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include "struct.h"

# define FOVH 100.0
# define FOVV 60.0
# define HEIGHT 1.0
# define HEIGT_PLAYER 0.5

# define WALL_DOOR "19"

// raycasting
void		detroy_render(t_render **render);
t_render	**ray_cast(t_player *player, char **grid, t_textures *textures);
// utils
double		degree_to_radian(double degree);
double		trigo_get_opposite_len(double angle, double len);
// ray render
t_render	*get_render(t_player *player, t_raycasting *rc,
				char **grid, t_textures *textures);
// ray setter
void		set_next_x(t_raycasting *raycasting);
void		set_next_y(t_raycasting *raycasting);
void		set_next_z(t_raycasting *raycasting);
void		set_ray(t_raycasting *raycasting);
// texture setter
void		set_texture_door(t_render *render, t_raycasting *rc,
				char **grid, t_textures *textures);
void		set_texture_classic(t_render *render, t_raycasting *rc,
				char **grid, t_textures *textures);

#endif