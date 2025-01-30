/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_destroy_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:31:39 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/30 22:32:28 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_destroy_image(t_env *env, void *ptr)
{
	if (ptr)
	{
		mlx_destroy_image(env->mlx->id, ptr);
		ptr = NULL;
	}
}
