/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:55:40 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 10:30:37 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

/*******************************/
/*            ENV              */
/*******************************/
# define NAME "[cub3D] "

# define WIN_TITLE "Cub3D - @UserCrixus & @MathysCogne"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define RESH (1280 / 2)
# define RESV (720 / 2)
# define VERTICAL_FIX ((720 / 2) * 3 / 180)

# define TICK_SPEED 100

/*******************************/
/*            GAME             */
/*******************************/
# define MOVE_SPEED 0.02 * 3
# define SPRINT_SPEED 0.04 * 3
# define MOVE_COLISION "19"
# define ANGLE_SPEED 4
# define MOUSE_SPEED 0.02

# define START_BULLETS 20
# define START_PV 10
# define START_STAMINA 5
# define REGEN_STAMINA 0.05
# define SPRINT_MIN_COST 0.1

# define TIME_RENDER_ANIM 80
# define FRAME_MAX_MONSTERS 4
# define FRAME_MAX_MUSK 5

/*******************************/
/*            PARSING          */
/*******************************/
# define EXTENTION_MAP ".cub"

# define CARAC_VOID ' '
# define CARAC_WALL '1'
# define CARAC_MONSTER '2'
# define CARAC_MUSK '3'
# define CARAC_BOT_BLOOD '4'
# define CARAC_DOOR_OPEN '8'
# define CARAC_DOOR '9'
# define CARAC_PLAYER "NSEW"

# define CARAC_DOOR_CO "98"
# define CARAC_ENNEMY "23"
# define CARAC_MAP " 0123NSEW9"
# define CARAC_MAP_NO_SPACE "0123NSEW9"
# define CARAC_PLAYER_VOID "023NSEW9"

# define MIN_RGB -1
# define NULL_RGB -1
# define MAX_RGB 255

/*******************************/
/*            MINIMAP          */
/*******************************/
# define MINIMAP_SIZE 10
# define MINIMAP_RADIUS 11
# define MINIMAP_SIZE_PLAYER 5
# define MINIMAP_COLOR_PLAYER 0xFF0000
# define MINIMAP_COLOR_ENNEMY 0xF70000
# define MINIMAP_COLOR_WALL 0x0000000
# define MINIMAP_COLOR_DOOR 0xF052E5
# define MINIMAP_COLOR_DOOR_OPEN 0xF072E5
# define MINIMAP_COLOR_VOID 0xF092E5
# define MINIMAP_COLOR_SPAWN 0xF092E5

/*******************************/
/*            HUD              */
/*******************************/
# define COLOR_TXT_INFO 0xFFFFFF
# define COLOR_TXT_RED 0xFF0000

# define TXT_DOOR_OPEN "USE 'SPACE' TO OPEN A DOOR"
# define TXT_DOOR_CLOSE "USE 'SPACE' TO CLOSE A DOOR"
# define TXT_ACTION_DOOR_CLOSE "Close Sesame !..\n"
# define TXT_ACTION_DOOR_OPEN "Open Sesame !..\n"
# define TXT_NO_BULLETS "NO AMMUNITION !"
# define TXT_LOW_PV "LOW LIFE !"
# define TXT_LOW_STAMINA "LOW STAMINA !"

# define TIME_RENDER_BAM 10

/*******************************/
/*            UTILS            */
/*******************************/
# define M_PI 3.14159265358979323846
# define HEX_BLACK 0xFF000000
# define HEX_BG_MAP 0x201E26

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