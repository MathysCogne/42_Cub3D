/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:45:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/18 23:51:37 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	len = end - start;
	path = malloc(sizeof(char) * (len + 1));
	if (!path)
		return (NULL);
	ft_strncpy(path, &line[start], len);
	path[len] = '\0';
	return (path);
}

static int	get_rgb(char *line, int *color)
{
	int		i;
	int		j;
	char	token[4];
	int		k;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (line[j] && ft_is_space(line[j]))
			j++;
		k = 0;
		while (line[j] && line[j] != ',' && line[j] != '\n' && k < 3)
			token[k++] = line[j++];
		token[k] = '\0';
		if (line[j] == ',')
			j++;
		color[i] = ft_atoi(token);
		if (color[i] < 0 || color[i] > 255)
			return (1);
		i++;
	}
	if (line[j] != '\0' && line[j] != '\n')
		return (1);
	return (0);
}

static int	parse_texture_line(char *line, t_textures *textures)
{
	size_t	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		textures->path_no = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		textures->path_so = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		textures->path_we = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		textures->path_ea = get_texture_path(&line[i] + 2);
	else if (ft_strncmp(&line[i], "F", 1) == 0)
		return (get_rgb(&line[i] + 1, textures->rgb_floor));
	else if (ft_strncmp(&line[i], "C", 1) == 0)
		return (get_rgb(&line[i] + 1, textures->rgb_ceiling));
	return (0);
}

short	find_player_pos(t_player *player, char *line, size_t y)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_strchr("NSEW", line[i]))
		{
			player->pos.y = y;
			player->pos.x = i;
			player->dir = line[i];
			if (player->dir == 'N')
				player->angle = 0;
			else if (player->dir == 'S')
				player->angle = 180;
			else if (player->dir == 'W')
				player->angle = 270;
			else if (player->dir == 'E')
				player->angle = 90;
			return (0);
		}
		i++;
	}
	return (0);
}

static int	parse_map_line(char *line, t_env *env, t_map *map)
{
	map->grid = ft_realloc(map->grid, sizeof(char *) * (map->height),
			sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (1);
	map->grid[map->height] = ft_strdup(line);
	gc_add(env->gc, map->grid[map->height]);
	if (!map->grid[map->height])
		return (1);
	if (map->width < ft_strclen(line, '\n'))
		map->width = ft_strclen(line, '\n');
	find_player_pos(&map->player, line, map->height);
	map->height++;
	return (0);
}

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_is_space(line[i]) && !ft_strchr("01NSEW", line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	process_line(char *line, t_env *env, int *parsing_map)
{
	if (*parsing_map || is_map_line(line))
	{
		*parsing_map = 1;
		return (parse_map_line(line, env, env->map));
	}
	return (parse_texture_line(line, env->textures));
}

short	process_map(t_env *env)
{
	char	*line;
	char	*next_line;
	int		parsing_map;
	int		i;

	line = env->map->file;
	parsing_map = 0;
	i = 0;
	while (line[i])
	{
		next_line = ft_strchr(&line[i], '\n');
		if (next_line)
			*next_line = '\0';
		if (process_line(&line[i], env, &parsing_map))
			return (1);
		if (next_line)
			i = next_line - line + 1;
		else
			break ;
	}
	return (0);
}
