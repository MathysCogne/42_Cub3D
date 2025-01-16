/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:37:24 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/15 22:45:26 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	ERROR_INIT_ENV,
	ERROR_PARSING,
	ERROR_MLX,
	ERROR_TEXTURES,
	ERROR_MAP,
	ERROR_GAME
}			t_error;

#endif