/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:14:34 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 13:13:23 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "error.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "key.h"
# include "libft.h"
# include "libft_extra.h"
# include "mlx.h"
# include "path_textures.h"
# include "ray_casting.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <pthread.h> 

/*******************************/
/*          ENV - MAIN         */
/*******************************/
short		exec(t_env *env);
short		parsing(t_env *env, char *path_map);

/*******************************/
/*            PARSING          */
/*******************************/
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
/*            RENDER           */
/*******************************/
short		render_map_3d(t_map *map, t_mlx *mlx, t_textures *texture);
int			loop_render(t_env *env);
void		bi_interpolation_decompression(t_mlx *mlx);
short		get_id_monsters(t_map *map);
short		get_id_musk(t_map *map);
int			render_sprites(t_map *map, t_render **render, t_mlx *mlx,
				t_textures *texture);

/*******************************/
/*             MLX             */
/*******************************/
short		ft_mlx_init_win(t_env *env, t_mlx *mlx);
short		ft_mlx_init_events(t_env *env);
short		ft_put_pixel_in_img(t_mlx *mlx, t_pos pos, int color);
int			ft_get_pixel_color(t_texture *texture, double offsetx,
				double offsety);
int			ft_get_pixel_color_hud(void *img, int x, int y);
short		handler_load_textures(t_env *env, t_textures *textures);
short		valid_textures(t_textures *textures);

/*******************************/
/*             GAME            */
/*******************************/
void		update_player_angle(t_map *map, double angle_h, double angle_v);
void		handler_move_player(t_env *env);
void		handler_action_weapon(t_env *env);
short		action_sprint(t_map *map, double x, double y);
void		regen_stamina(t_env *env);
void		handler_action_hands_fights(t_env *env);

/*******************************/
/*             HUD             */
/*******************************/
void		handler_mini_map(t_env *env);
void		handler_hud(t_env *env);
void		handler_door(t_env *env);
void		handler_waepon(t_env *env);
void		handler_put_strings(t_env *env);
void		handler_hud_stats_player(t_env *env);
void		handler_menu(t_env *env);
void		helper_mlx_put_hud_to_win(t_env *env, t_texture texture, t_pos pos);
void		hud_bam_comics(t_env *env, short state_check);
void		helper_mlx_put_width_max_hud_to_win(t_env *env, t_texture texture,
				t_pos pos, int width_max);
void		helper_mlx_put_height_start_hud_to_win(t_env *env,
				t_texture texture, t_pos pos, int height_start);

/*******************************/
/*           SPRITES           */
/*******************************/
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
void		ft_mlx_destroy_image(t_env *env, void *ptr);

/*******************************/
/*          DEBUG MODE         */
/*******************************/
void		debug_parsing(t_env *env);

#endif