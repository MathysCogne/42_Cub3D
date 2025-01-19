/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:05:18 by achaisne          #+#    #+#             */
/*   Updated: 2025/01/19 03:13:50 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cub3d.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define HEIGHT_VIEW 0.5
#define HEIGHT_MAP 1
#define HORIZONTAL_FIELD_VIEW 200
#define VERTICAL_FIELD_VIEW 150
#define EPSILON 1e-6
#ifndef M_PI
#define M_PI acos(-1.0)
#endif

void	debug(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < ft_strlen("11111"))
		{
			printf("(%c ", env->map.grid[y][x].value);
			printf("%i ", env->map.grid[y][x].render_ouest);
			printf("%i ", env->map.grid[y][x].render_south);
			printf("%i ", env->map.grid[y][x].render_north);
			printf("%i)", env->map.grid[y][x].render_est);
			x++;
		}
		printf("\n");
		y++;
	}
}

double normalize_angle_degree(double angle) {
    if (angle < 0)
		angle += 360.0;
    else if (angle >= 360.0)
		angle -= 360.0;
    return angle;
}

double radian_to_dregree(double degree)
{
	return (degree * (180.0 / M_PI));
}

bool is_in_view(int y, int x, t_env *env) {
    double angle_to_point = radian_to_dregree(atan2(y - env->map.player.pos.y, x - env->map.player.pos.x));
    angle_to_point = normalize_angle_degree(angle_to_point);
    double angle_left = normalize_angle_degree(env->map.player.dir - (HORIZONTAL_FIELD_VIEW / 2));
    double angle_right = normalize_angle_degree(env->map.player.dir + (HORIZONTAL_FIELD_VIEW / 2));
    if (angle_left <= angle_right) {
        return (angle_to_point >= angle_left && angle_to_point <= angle_right);
    } else {
        return (angle_to_point >= angle_left || angle_to_point <= angle_right);
    }
}

double	get_distance(int y, int x, t_env *env)
{
	if (x <= env->map.player.pos.y && y <= env->map.player.pos.x)
		return sqrt(pow(env->map.player.pos.y - x, 2) + pow(env->map.player.pos.x - y, 2));
	else if (x >= env->map.player.pos.y && y <= env->map.player.pos.x)
		return sqrt(pow(x - env->map.player.pos.y, 2) + pow(env->map.player.pos.x - y, 2));
	else if (x <= env->map.player.pos.y && y >= env->map.player.pos.x)
		return sqrt(pow(env->map.player.pos.y - x, 2) + pow(y - env->map.player.pos.x, 2));
	else if (x >= env->map.player.pos.y && y >= env->map.player.pos.x)
		return sqrt(pow(x - env->map.player.pos.y, 2) + pow(y - env->map.player.pos.x, 2));
	return (-1);
}

// view of 360 to start
int	get_vue_data(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < ft_strlen("11111"))
		{
			if (is_in_view(y, x, env)) {
				if (x < env->map.player.pos.x) {
					env->map.grid[y][x].render_ouest = 1;
				} else if (x > env->map.player.pos.x) {
					env->map.grid[y][x].render_est = 1;
				}
				if (y < env->map.player.pos.y) {
					env->map.grid[y][x].render_north = 1;
				} else if (y > env->map.player.pos.y) {
					env->map.grid[y][x].render_south = 1;
				}
			}
			env->map.grid[y][x].distance = get_distance(y, x, env);
			env->map.grid[y][x].dist_top_ouest = sqrt(pow(env->map.grid[y][x].distance, 2) + pow(HEIGHT_VIEW - HEIGHT_MAP, 2));
			env->map.grid[y][x].dist_bot_ouest = sqrt(pow(env->map.grid[y][x].distance, 2) + pow(HEIGHT_VIEW, 2));
			if (x > 0)
			{
				env->map.grid[y][x - 1].dist_top_est = env->map.grid[y][x].dist_top_ouest;
				env->map.grid[y][x - 1].dist_bot_est = env->map.grid[y][x].dist_bot_ouest;
			}
			x++;
		}
		env->map.grid[y][x - 1].dist_top_est = get_distance(y, x, env);;
		env->map.grid[y][x - 1].dist_bot_est = get_distance(y, x, env);;
		y++;
	}
	debug(env);
}

int main()
{
	char	*grid[] = {"11111", "10101", "10201", "10101", "11111"};
	t_env	env;
	env.map.grid = calloc(sizeof(t_grid *), 5);
	int		y;
	int		x;

	env.map.player.pos.y = 2;
	env.map.player.pos.x = 2;
	env.map.player.dir = 90;

	y = 0;
	while (y < 5)
	{
		env.map.grid[y] = calloc(sizeof(t_grid), ft_strlen("11111"));
		x = 0;
		while (x < ft_strlen("11111"))
		{
			env.map.grid[y][x].value = grid[y][x];
			x++;
		}
		env.map.grid[y][x].value = 0;
		y++;
	}
	get_vue_data(&env);;
}


/*
TEST MAP
11111
10101
10201
10101
11111

cmd :
gcc src/exec/ray_casting/ray_casting.c libft/libft.a -I./include -I./libft/include -I./minilibx-linux -lm
*/