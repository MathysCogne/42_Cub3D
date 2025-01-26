/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_textures_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:04:03 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/26 15:27:11 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	is_texture_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] == '\n' || !line[i])
		return (1);
	if (!ft_strncmp(&line[i], "NO", 2) || !ft_strncmp(&line[i], "SO", 2)
		|| !ft_strncmp(&line[i], "WE", 2) || !ft_strncmp(&line[i], "EA", 2)
		|| !ft_strncmp(&line[i], "F", 1) || !ft_strncmp(&line[i], "C", 1))
		return (1);
	return (0);
}
