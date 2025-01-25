/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:34:09 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/25 18:58:46 by mcogne--         ###   ########.fr       */
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

typedef struct s_event
{
	short			move_forward;
	short			move_back;
	short			move_right;
	short			move_left;
	short			move_sprint;
	short			angle_v_right;
	short			angle_v_left;
	short			angle_h_up;
	short			angle_h_down;
	short			capture_mouse;
}					t_event;

typedef struct s_raycasting
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			ray_dir_z;
	double			next_x;
	double			next_y;
	double			next_z;
	double			side_dist_x;
	double			side_dist_y;
	double			side_dist_z;
}					t_raycasting;

typedef struct s_ray
{
	double			y;
	double			x;
	double			z;
	double			angle_h;
	double			angle_v;
	int				index;
}					t_ray;

typedef struct s_render
{
	double			offset_x;
	double			offset_y;
	t_texture_type	pole;
}					t_render;

typedef struct s_mlx
{
	void			*id;
	void			*win;
	void			*render_pixel;
	int				*render_pixel_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct texture
{
	int				width;
	int				height;
	void			*value;
}					t_texture;

typedef struct textures
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*path_bot;
	char			*path_top;
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		top;
	t_texture		bot;
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
	float			y;
	float			x;
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
	t_event			*event;
	int				err;
}					t_env;

#endif