/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:14:34 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/19 23:59:15 by mcogne--         ###   ########.fr       */
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

# define RENDER_SIZE 32

# define MOVE_SPEED 0.05
# define ANGLE_SPEED 2

# define M_PI 3.14159265358979323846

/*******************************/
/*            PARSING          */
/*******************************/
short	parsing(t_env *env, char *path_map);
short	read_map(t_env *env, char *path_map);
short	process_map(t_env *env);
void	cleanup(t_env *env);
short	handler_validate_parsing(t_env *env, t_map *map);

/*******************************/
/*             EXEC            */
/*******************************/
short	exec(t_env *env);
// RENDER //
short	render_map_2d(t_map *map, t_mlx *mlx);
// MLX //
short	ft_mlx_init_win(t_mlx *mlx);
short	ft_mlx_init_events(t_env *env);
short	ft_put_pixel_in_img(t_mlx *mlx, t_pos pos, int color);
// GAME //
short	handler_move_player(t_env *env, int keycode);

/*******************************/
/*            UTILS            */
/*******************************/
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