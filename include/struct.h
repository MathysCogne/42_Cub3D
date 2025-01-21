/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:34:09 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/21 21:10:32 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft_extra.h"

typedef enum e_texture_type
{
	FOG,
	NO,
	SO,
	WE,
	EA,
	TOP,
	BOT
}					t_texture_type;

typedef struct s_raycasting
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	ray_dir_z;
	double	next_x;
	double	next_y;
	double	next_z;
	double	side_dist_x;
	double	side_dist_y;
	double	side_dist_z;
}	t_raycasting;

typedef struct s_ray
{
	double	y;
	double	x;
	double	z;
	double	angle_h;
	double	angle_v;
	int		index;
}	t_ray;

typedef struct s_render
{
	double			offset_x;
	double			offset_y;
	t_texture_type	pole;
}	t_render;

typedef struct s_mlx
{
	void			*id;
	void			*win;
	// ICI POUR LES TESTS, BOUGERAS PEUT ETRE
	void			*render_pixel;
	int				*render_pixel_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct textures
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	void			*t_no;
	void			*t_so;
	void			*t_we;
	void			*t_ea;
	int				t_width;
	int				t_height;
	int				rgb_floor[3];
	int				rgb_ceiling[3];
}					t_textures;

typedef struct s_pos
{
	size_t			x;
	size_t			y;
}					t_pos;

typedef struct s_pos_player
{
	float			x;
	float			y;
	float			angle_h;
	double			angle_v;
}					t_pos_player;

typedef struct s_player
{
	t_pos_player	pos;
	char			dir;
}					t_player;

typedef struct s_map
{
	char			*file;
	char			**grid;
	size_t			width;
	size_t			height;
	t_player		player;
}					t_map;

typedef struct s_env
{
	t_gc			*gc;
	t_map			*map;
	t_textures		*textures;
	t_mlx			*mlx;
	int				err;
}					t_env;

#endif