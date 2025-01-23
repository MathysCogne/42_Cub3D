/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:14:34 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/23 13:37:03 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "key.h"
# include "libft.h"
# include "libft_extra.h"
# include "mlx.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
// DEBUG //
# include <stdio.h>

# ifndef DEBUG_MODE
#  define DEBUG_MODE 1
# endif

/*******************************/
/*            DEFINE           */
/*******************************/
# define NAME "[cub3D] "

# define EXTENTION_MAP ".cub"

# define CARAC_MAP " 01NSEW"
# define CARAC_PLAYER "NSEW"
# define CARAC_PLAYER_VOID "0NSEW"

# define WIN_TITLE "Cub3D - @UserCrixus & @MathysCogne"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

# define TEXTURE_WIDTH 500  // TODO: A ADAPTER EN FONCTION DES TEXTURES
# define TEXTURE_HEIGHT 500 //

# define RENDER_SIZE_2D 32

# define MOVE_SPEED 0.05
# define ANGLE_SPEED 4
# define MOUSE_SPEED 0.4

# define M_PI 3.14159265358979323846

/*******************************/
/*            PARSING          */
/*******************************/
short	parsing(t_env *env, char *path_map);
short	read_map(t_env *env, char *path_map);

short	process_map(t_env *env);
short	parse_texture_line(char *line, t_textures *textures);
short	process_map(t_env *env);
int		parse_map_line(char *line, t_env *env, t_map *map);

short	handler_validate_parsing(t_env *env, t_map *map);
short	handler_valid_data(t_env *env, t_textures *textures);
short	valid_carac(t_map *map);
short	valid_close_wall(t_map *map, char **grid);
short	valid_player(t_map *map, char **grid);

/*******************************/
/*             EXEC            */
/*******************************/
short	exec(t_env *env);

/* RENDER */
short	render_map_2d(t_map *map, t_mlx *mlx);
short	render_env_3d(t_map *map, t_mlx *mlx, t_textures *texture);

/* MLX */
short	ft_mlx_init_win(t_env *env, t_mlx *mlx);
short	ft_mlx_init_events(t_env *env);
short	ft_put_pixel_in_img(t_mlx *mlx, t_pos pos, int color);

/* GAME */
short	handler_move_player(t_env *env, int keycode);
short	update_player_angle(t_env *env, float angle);

/*******************************/
/*            UTILS            */
/*******************************/
void	cleanup(t_env *env);
short	init_env(t_env *env);
void	ft_free(void *ptr);
short	ft_is_space(char c);
size_t	ft_strclen(char *s, char chr);
short	is_map_line(char *line);
short	is_texture_line(char *line);
char	*get_msg_error(size_t err);

/*******************************/
/*          DEBUG MODE         */
/*******************************/
void	debug_parsing(t_env *env);

/*******************************/
/*            COLORS           */
/*******************************/
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define UDERLINE "\033[4m"
# define C_RESET "\033[0m"
# define TURQUOISE_BLUE "\033[38;2;0;184;169m"
# define DARK_GRAY "\033[38;2;47;52;59m"
# define PALE_PINK "\033[38;2;245;166;195m"
# define MINT_GREEN "\033[38;2;136;199;153m"

#endif