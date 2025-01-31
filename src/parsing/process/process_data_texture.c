/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_data_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:56:06 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/31 10:36:46 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	get_rgb(char *line, int *rbg)
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
		if (!ft_isdigit(token[0]))
			return (0);
		rbg[i] = ft_atoi(token);
		i++;
	}
	if (line[j] != '\0' && line[j] != '\n')
		return (1);
	return (0);
}

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

short	parse_texture_line(char *line, t_textures *textures)
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
	{
		textures->path_bot = get_texture_path(&line[i] + 2);
		return (get_rgb(&line[i] + 1, textures->rgb_floor));
	}
	else if (ft_strncmp(&line[i], "C", 1) == 0)
	{
		textures->path_top = get_texture_path(&line[i] + 2);
		return (get_rgb(&line[i] + 1, textures->rgb_ceiling));
	}
	return (0);
}
