/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:14:34 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/19 01:08:37 by achaisne         ###   ########.fr       */
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

# ifndef DEBUG_MODE
#  define DEBUG_MODE 1
# endif
/*******************************/
/*            DEFINE           */
/*******************************/
# define NAME "[cub3D] "

# define EXTENTION_MAP ".cub"

# define WIN_TITLE "Cub3D - @UserCrixus & @MathysCogne"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

/*******************************/
/*            PARSING          */
/*******************************/
short	parsing(t_env *env, char *path_map);
short	read_map(t_env *env, char *path_map);
short	process_map(t_env *env);
void	cleanup(t_env *env);

/*******************************/
/*             EXEC            */
/*******************************/
short	exec(t_env *env);

/*******************************/
/*             GAME            */
/*******************************/

/*******************************/
/*            UTILS            */
/*******************************/
short	init_env(t_env *env);
void	ft_free(void *ptr);
short	ft_is_space(char c);

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