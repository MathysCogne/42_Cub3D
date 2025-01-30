/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:03:18 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 23:04:51 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_is_space(line[i]) && !ft_strchr(CARAC_MAP_NO_SPACE, line[i]))
			return (0);
		i++;
	}
	return (1);
}
