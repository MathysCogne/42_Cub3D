/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:34:09 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 09:52:56 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft_extra.h"

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
	short			click_right;
	short			click_left;
	short			menu_start;
	short			menu_died;
	short			menu_happy_end;
}					t_event;

typedef struct s_ray
{
	double			y;
	double			x;
	double			z;
	double			angle_h;
	double			angle_v;
}					t_ray;

typedef struct s_raycasting
{
	t_ray			ray;
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

typedef struct s_render
{
	double			offset_x;
	double			offset_y;
	double			distance;
	t_texture		*texture;
}					t_render;

typedef struct textures
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*path_bot;
	char			*path_top;
	// wall
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		top;
	t_texture		bot;
	t_texture		bot_blood;
	// door
	t_texture		door_no;
	t_texture		door_so;
	t_texture		door_we;
	t_texture		door_ea;
	// hub
	t_texture		weapon_off;
	t_texture		weapon_on;
	t_texture		hud_border_map;
	t_texture		hud_card_id;
	t_texture		hud_pv;
	t_texture		hud_pv_rod;
	t_texture		hud_stamina;
	t_texture		hud_stamina_rod;
	t_texture		hud_bam;
	// sprite
	t_texture		musk[5];
	t_texture		monster[4];
	// menu
	t_texture		menu_start;
	t_texture		menu_end;
	t_texture		menu_happy_end;
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
	double			x;
	double			y;
	double			angle_h;
	double			angle_v;
}					t_pos_player;

typedef struct s_prite
{
	t_pos			pos;
	int				render;
	int				offsetx;
	int				offsety;
	double			angle_diff;
	double			distance;
	double			sprite_height;
	double			sprite_width;
	t_texture		*texture;
}					t_sprite;

typedef struct s_player
{
	t_pos_player	pos;
	char			dir;
	size_t			bullets;
	size_t			pv;
	double			stamina;
}					t_player;

typedef struct s_map
{
	char			*file;
	char			**grid;
	size_t			height;
	t_player		player;
	int				sprites_size;
	pthread_mutex_t	mutex_sprite;
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