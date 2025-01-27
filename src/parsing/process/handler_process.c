/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:45:00 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/27 18:28:36 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_line(char *line, t_env *env, int *parsing_map)
{
	if (is_texture_line(line) && !*parsing_map)
		return (parse_texture_line(line, env->textures));
	else if (*parsing_map || is_map_line(line))
	{
		*parsing_map = 1;
		return (parse_map_line(line, env, env->map));
	}
	else
		return (0);
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
		{
			i = next_line - line + 1;
			*next_line = '\n';
		}
		else
			break ;
	}
	return (0);
}
