/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:37:24 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 17:40:38 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	ERR_INIT_ENV = 2,
	ERR_PARSE_READ,
	ERR_PARSE_PROCESS,
	ERR_PARSE_CARAC,
	ERR_PARSE_WALL,
	ERR_PARSE_DATA,
	ERR_PARSE_PLAYER,
	ERR_PARSE_DOOR,
	ERR_MLX,
	ERR_GAME
}	t_error;

#endif