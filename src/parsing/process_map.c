/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:45:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/16 02:08:14 by mcogne--         ###   ########.fr       */
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

static char	*get_texture_path(char *line)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*path;

	start = 0;
	end = 0;
	while (line[start] && ft_is_space(line[start]))
		start++;
	end = start;
	while (line[end] && line[end] != '\n' && !ft_is_space(line[end]))
		end++;
	len = (end + 1) - start;
	path = malloc(sizeof(char) * len + 1);
	if (!path)
		return (NULL);
	ft_strncpy(path, line, len);
	path[len] = '\0';
	return (path);
}

static void	parse_texture_line(char *line, t_textures *textures)
{
	size_t	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		textures->no = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		textures->so = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		textures->we = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		textures->ea = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "F", 1) == 0)
		textures->floor = get_texture_path(&line[i] + 1);
	else if (ft_strncmp(&line[i], "C", 1) == 0)
		textures->ceiling = get_texture_path(&line[i] + 1);
}

static short	get_path_texture(t_map *map, t_textures *textures)
{
	size_t	i;

	i = 0;
	while (map->file[i])
	{
		while (map->file[i] && ft_is_space(map->file[i]))
			i++;
		parse_texture_line(&map->file[i], textures);
		while (map->file[i] && map->file[i] != '\n')
			i++;
		if (map->file[i] == '\n')
			i++;
	}
	if (!textures->no || !textures->so || !textures->we || !textures->ea
		|| !textures->floor || !textures->ceiling)
		return (1);
	return (0);
}

static short	handle_matrix_map(t_map *map)
{
	(void)map;
	return (0);
}

short	process_map(t_env *env)
{
	if (get_path_texture(env->map, env->textures))
		return (1);
	if (handle_matrix_map(env->map))
		return (1);
	return (0);
}
