/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:46:46 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 22:13:41 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Parsing Example:
**
** NO ./path_to_the_north_texture
** SO ./path_to_the_south_texture
** WE ./path_to_the_west_texture
** EA ./path_to_the_east_texture
**
** F 220,100,0
** C 225,30,0
**
**         1111111111111111111111111
**         1000000000110000000000001
**         1011000001110000000000001
**         1001000000000000000000001
** 111111111011000001110000000000001
** 100000000011000001110111111111111
** 11110111111111011100000010001
** 11110111111111011101010010001
** 11000000110101011100000010001
** 10000000000000001100000010001
** 10000000000000001101010010001
** 11000001110101011111011110N0111
** 11110111 1110101 101111010001
** 11111111 1111111 111111111111
*/

static void	welcome_print(void)
{
	ft_printf(YELLOW "\nYour mission, should you choose to accept it:\n\n"
		"Kill the big villain.\n"
		"To achieve this, "
		"you will have to go through his armed guards!\n\n" C_RESET);
}

short	parsing(t_env *env, char *path_map)
{
	welcome_print();
	if (read_map(env, path_map))
		return (env->err = ERR_PARSE_READ, 1);
	if (process_map(env))
		return (env->err = ERR_PARSE_PROCESS, 1);
	if (handler_validate_parsing(env, env->map))
		return (1);
	debug_parsing(env);
	return (0);
}
