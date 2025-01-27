/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:17:05 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 17:57:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

typedef enum e_key
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_TOP = 65362,
	KEY_BOT = 65364,
	KEY_SHIFT = 65505,
	KEY_CAPSLOCK = 65509,
	KEY_SPACE = 32
}	t_key;

typedef enum e_key_mouse
{
	KEY_MOUSE_LEFT = 1,
	KEY_MOUSE_MIDDLE,
	KEY_MOUSE_RIGHT,
	KEY_MOUSE_SCROOL_UP,
	KEY_MOUSE_SCROOL_DOWN
}	t_key_mouse;

#endif