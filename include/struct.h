/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:34:09 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/17 20:49:13 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft_extra.h"

typedef struct s_mlx
{
	void		*id;
	void		*win;
}				t_mlx;

typedef struct textures
{
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	void		*t_no;
	void		*t_so;
	void		*t_we;
	void		*t_ea;
	int			rgb_floor[3];
	int			rgb_ceiling[3];
}				t_textures;

typedef struct s_pos
{
	size_t		x;
	size_t		y;
}				t_pos;

typedef struct s_player
{
	t_pos		pos;
	char		dir;
}				t_player;

typedef struct s_grid
{
	char		value;
	double		angle;
	double		distance;
}				t_grid;

typedef struct s_map
{
	char		*file;
	t_grid		**grid;
	size_t		width;
	size_t		height;
	t_player	player;
}				t_map;

typedef struct s_env
{
	t_gc		*gc;
	t_map		*map;
	t_textures	*textures;
	t_mlx		*mlx;
}				t_env;

#endif