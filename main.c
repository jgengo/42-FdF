/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:04:24 by jgengo            #+#    #+#             */
/*   Updated: 2017/01/19 10:22:21 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		init_env(t_env *e)
{
	if ((e->mlx = mlx_init()) == (void *)0)
		exit_error(2);
	e->scale.x = 30;
	e->scale.y = -30;
	e->pos.x = 400;
	e->pos.y = 400;
	e->alt = 1;
	e->color = CZ;
}

static void		recalc_scale(t_env *e)
{
	while (e->scale.x * e->width > WIN_X && e->scale.x > 0)
		e->scale.x -= 1;
	while (e->scale.y * e->height < -WIN_Y && e->scale.y < 0)
		e->scale.y += 1;
	if (ft_abs(e->scale.x) < ft_abs(e->scale.y))
		e->scale.y = -(e->scale.x);
	else
		e->scale.x = -(e->scale.y);
}

void			pixel_put(t_env *e, int x, int y, int color)
{
	mlx_pixel_put(e->mlx, e->win, e->pos.x + x, e->pos.y + y, color);
}

int				main(int ac, char **av)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env == NULL)
		return (1);
	check_args(ac);
	init_env(env);
	parse_args(av[1], env);
	read_args(av[1], env);
	recalc_scale(env);
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "test");
	if (env->win == (void *)0)
		exit_error(2);
	draw_again(env);
	mlx_key_hook(env->win, event_key, env);
	mlx_mouse_hook(env->win, event_mouse, env);
	mlx_loop(env->mlx);
}
