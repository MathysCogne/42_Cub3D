/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_by_user.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:46:42 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 18:25:15 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_user(t_env *env)
{
	cleanup(env);
	if (env->err)
	{
		ft_printf(NAME "Exit with error %d\n", env->err);
		exit(env->err);
	}
	else
	{
		ft_printf(NAME "Goodbye 👋\n");
		exit(0);
	}
}
