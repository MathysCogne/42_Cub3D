/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:32:20 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/17 04:37:44 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static short	cub3d(t_env *env, char *path_map)
{
	if (init_env(env))
		return (ERROR_INIT_ENV);
	if (parsing(env, path_map))
		return (ERROR_PARSING);
	if (exec(env))
		return (ERROR_GAME);
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
		ft_fprintf(2, RED NAME "Error\n");
		return (1);
	}
	cleanup(&env);
	ft_fprintf(1, MINT_GREEN NAME "Exit\n");
	return (0);
}
