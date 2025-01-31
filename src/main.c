/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:32:20 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/31 11:39:24 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	cub3d(t_env *env, char *path_map)
{
	if (init_env(env))
		return (env->err = ERR_INIT_ENV, 1);
	if (parsing(env, path_map))
		return (1);
	if (exec(env))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2 || !argv[1][0])
	{
		ft_fprintf(2, RED NAME "Usage: %s [path_map]\n", argv[0]);
		return (1);
	}
	if (cub3d(&env, argv[1]))
	{
		cleanup(&env);
		ft_fprintf(2, RED BOLD NAME "Error\n" C_RESET);
		ft_fprintf(2, NAME "%s\n", get_msg_error(env.err));
		if (env.err)
			return (env.err);
		return (1);
	}
	cleanup(&env);
	ft_fprintf(1, MINT_GREEN NAME "Exit\n");
	return (0);
}
