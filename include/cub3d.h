/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:14:34 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/29 22:49:28 by mcogne--         ###   ########.fr       */
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
# include "ray_casting.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
// DEBUG //
# include <stdio.h>

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

/*******************************/
/*            DEFINE           */
/*******************************/
// ENV
# define NAME "[cub3D] "

# define WIN_TITLE "Cub3D - @UserCrixus & @MathysCogne"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define RESH 1080 / 2
# define RESV 720 / 2
# define VERTICAL_FIX RESV * 3 / 180

# define TICK_SPEED 200

// GAME
# define MOVE_SPEED 0.05
# define SPRINT_SPEED 0.09
# define MOVE_COLISION "19"
# define ANGLE_SPEED 4
# define MOUSE_SPEED 0.02

# define START_BULLETS 20
# define START_PV 10
# define START_STAMINA 5
# define REGEN_STAMINA 0.05
# define SPRINT_MIN_COST 0.1

# define TIME_RENDER_ANIM 10
# define FRAME_MAX_MONSTERS 4
# define FRAME_MAX_MUSK 5

// PARSING
# define EXTENTION_MAP ".cub"
# define CARAC_MAP " 0123NSEW9"
# define CARAC_MAP_NO_SPACE "0123NSEW9"
# define CARAC_PLAYER "NSEW"
# define CARAC_PLAYER_VOID "023NSEW9"
# define CARAC_DOOR '9'
# define CARAC_DOOR_OPEN '8'
# define CARAC_DOOR_CO "98"
# define CARAC_ENNEMY "23"

// MINIMAP
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

// HUD
# define COLOR_TXT_INFO 0xFFFFFF
# define COLOR_TXT_RED 0xFF0000

# define TXT_DOOR_OPEN "USE 'SPACE' FOR OPEN A DOOR"
# define TXT_DOOR_CLOSE "USE 'SPACE' FOR CLOSE A DOOR"
# define TXT_NO_BULLETS "NO AMMUNITION !"
# define TXT_LOW_PV "LOW LIFE !"
# define TXT_LOW_STAMINA "LOW STAMINA !"

# define TIME_RENDER_BAM 10

// UTILS
# define M_PI 3.14159265358979323846

// PATH TEXTURES BONUS
# define PATH_WEAPON_ON "./assets/texture/weapon_00.xpm"
# define PATH_WEAPON_OFF "./assets/texture/weapon_01.xpm"

# define PATH_MONSTER_00 "./assets/texture/monster/monster_00.xpm"
# define PATH_MONSTER_01 "./assets/texture/monster/monster_01.xpm"
# define PATH_MONSTER_02 "./assets/texture/monster/monster_02.xpm"
# define PATH_MONSTER_03 "./assets/texture/monster/monster_03.xpm"

# define PATH_MUSK_00 "./assets/texture/musk/musk_00.xpm"
# define PATH_MUSK_01 "./assets/texture/musk/musk_01.xpm"
# define PATH_MUSK_02 "./assets/texture/musk/musk_02.xpm"
# define PATH_MUSK_03 "./assets/texture/musk/musk_03.xpm"
# define PATH_MUSK_04 "./assets/texture/musk/musk_04.xpm"

# define PATH_BORDER_MAP "./assets/texture/HUD/border_map.xpm"
# define PATH_CARD_ID "./assets/texture/HUD/card_id.xpm"
# define PATH_PV "./assets/texture/HUD/pv.xpm"
# define PATH_PV_ROD "./assets/texture/HUD/pv_rod.xpm"
# define PATH_STAMINA "./assets/texture/HUD/stamina.xpm"
# define PATH_STAMINA_ROD "./assets/texture/HUD/stamina_rod.xpm"

# define PATH_BAM "./assets/texture/HUD/bam.xpm"

# define PATH_START "./assets/texture/MENU/start.xpm"
# define PATH_DIED "./assets/texture/MENU/menu_died.xpm"
# define PATH_END "./assets/texture/MENU/died.xpm"

# define PATH_BOT_BLOOD "./assets/texture/BOT_BLOOD.xpm"
# define PATH_DOOR_NO "./assets/texture/doors/NO.xpm"
# define PATH_DOOR_SO "./assets/texture/doors/SO.xpm"
# define PATH_DOOR_EA "./assets/texture/doors/EA.xpm"
# define PATH_DOOR_WE "./assets/texture/doors/WE.xpm"

/*******************************/
/*            PARSING          */
/*******************************/
short		parsing(t_env *env, char *path_map);
short		read_map(t_env *env, char *path_map);

short		process_map(t_env *env);
short		parse_texture_line(char *line, t_textures *textures);
short		process_map(t_env *env);
int			parse_map_line(char *line, t_env *env, t_map *map);

short		handler_validate_parsing(t_env *env, t_map *map);
short		handler_valid_data(t_env *env, t_textures *textures);
short		valid_carac(t_map *map);
short		valid_close_wall(t_map *map, char **grid);
short		valid_player(t_map *map, char **grid);
short		valid_door(t_map *map, char **grid);

/*******************************/
/*             EXEC            */
/*******************************/
short		exec(t_env *env);

/* RENDER */
short		render_map_3d(t_map *map, t_mlx *mlx, t_textures *texture);
int			loop_render(t_env *env);
void		bi_interpolation_decompression(t_mlx *mlx);
short		get_id_monsters(t_map *map);
short		get_id_musk(t_map *map);
int			render_sprites(t_map *map, t_render **render, t_mlx *mlx,
				t_textures *texture);

/* MLX */
short		ft_mlx_init_win(t_env *env, t_mlx *mlx);
short		ft_mlx_init_events(t_env *env);
short		ft_put_pixel_in_img(t_mlx *mlx, t_pos pos, int color);
int			ft_get_pixel_color(t_texture *texture, double offsetx,
				double offsety);
int			ft_get_pixel_color_hud(void *img, int x, int y);
short		handler_load_textures(t_env *env, t_textures *textures);

/* GAME */
short		update_player_angle(t_map *map, double angle_h, double angle_v);
short		handler_move_player(t_env *env);
short		handler_action_weapon(t_env *env);
short		action_sprint(t_map *map, double x, double y);
short		regen_stamina(t_env *env);
short		handler_action_hands_fights(t_env *env);

/* HUD */
short		handler_mini_map(t_env *env);
short		handler_hud(t_env *env);
short		handler_door(t_env *env);
short		handler_waepon(t_env *env);
short		handler_put_strings(t_env *env);
short		handler_hud_stats_player(t_env *env);
short		handler_menu(t_env *env);
short		helper_mlx_put_hud_to_win(t_env *env, t_texture texture, t_pos pos);
void		hud_bam_comics(t_env *env, short state_check);
short		helper_mlx_put_width_max_hud_to_win(t_env *env, t_texture texture,
				t_pos pos, int width_max);
short		helper_mlx_put_height_start_hud_to_win(t_env *env,
				t_texture texture, t_pos pos, int height_start);

/* SPRITES */
t_sprite	*get_sprites(t_map *map, t_textures *textures);
void		sort_sprites(t_sprite *sprites, t_map *map, int (*compare)(int,
					int));
t_pos		is_sprites_shot(t_map *map, t_textures *textures);
t_texture	*get_texture(char c, t_textures *textures, t_map *map);
int			normalize_width(int img_width);
int			normalize_height(int img_height);

/*******************************/
/*            UTILS            */
/*******************************/
void		cleanup(t_env *env);
short		init_env(t_env *env);
void		ft_free(void *ptr);
short		ft_is_space(char c);
size_t		ft_strclen(char *s, char chr);
short		is_map_line(char *line);
short		is_texture_line(char *line);
char		*get_msg_error(size_t err);
int			exit_user(t_env *env);
double		normalize_angle_h(double angle);
double		normalize_angle_v(double angle);
int			rgb_to_hex(int *rgb);
short		player_adjacent_door(char **grid, size_t y, size_t x);
short		player_adjacent_close_door(char **grid, size_t y, size_t x);
short		player_adjacent_open_door(char **grid, size_t y, size_t x);
int			is_superior(int a, int b);
int			is_inferior(int a, int b);
double		trigo_get_angle(double sprite_dy, double sprite_dx);
double		trigo_get_hypotenuse_len(double sprite_dy, double sprite_dx);

/*******************************/
/*          DEBUG MODE         */
/*******************************/
void		debug_parsing(t_env *env);

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