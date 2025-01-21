/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:17:05 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/21 22:53:33 by mcogne--         ###   ########.fr       */
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
	KEY_RIGHT = 65363
}	t_key;

typedef enum e_key_mouse
{
	KEY_MOUSE_LEFT = 1,
	KEY_MOUSE_RIGHT,
	KEY_MOUSE_MIDDLE,
	KEY_MOUSE_SCROOL_UP,
	KEY_MOUSE_SCROOL_DOWN
}	t_key_mouse;

#endif