/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:32:20 by mcogne--          #+#    #+#             */
/*   Updated: 2025/01/15 18:41:39 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_fprintf(2, RED NAME "Usage: %s [path_map]\n", argv[0]);
		return (1);
	}
	if (!argv)
		return (1);
	ft_fprintf(2, MINT_GREEN NAME "Exit\n");
	return (0);
}