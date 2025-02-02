/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:43:29 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 09:50:19 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	check_extention_map(char *path_map)
{
	size_t	len;

	len = ft_strlen(path_map);
	if (len < 4)
		return (1);
	if (ft_strncmp(path_map + len - 4, EXTENTION_MAP, len))
		return (1);
	return (0);
}

short	read_map(t_env *env, char *path_map)
{
	int		fd;
	char	*line;
	char	*tmp;

	if (check_extention_map(path_map))
		return (1);
	fd = open(path_map, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(env->map->file, line);
		if (!tmp)
			return (ft_free(line), close(fd), 1);
		ft_free(env->map->file);
		ft_free(line);
		env->map->file = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
