/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bam_comics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:46:50 by mcogne--          #+#    #+#             */
/*   Updated: 2025/02/02 07:51:09 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** STATE_CHECK = 0 -> For check and print if state = 1
** STATE_CHECK = 1 -> Set state to 1 for print
*/
void	hud_bam_comics(t_env *env, short state_check)
{
	static short	render_count;
	static short	state;
	t_pos			pos;

	if (state_check)
		state = 1;
	if (state)
	{
		pos.x = 0;
		pos.y = 0;
		helper_mlx_put_hud_to_win(env, env->textures->hud_bam, pos);
		render_count++;
		if (render_count >= TIME_RENDER_BAM)
		{
			render_count = 0;
			state = 0;
		}
	}
}
