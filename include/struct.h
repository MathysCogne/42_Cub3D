/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:34:09 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/15 23:14:14 by mcogne--         ###   ########.fr       */
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
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor;
	char		*ceiling;
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

typedef struct s_map
{
	char		*file;
	char		**map;
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