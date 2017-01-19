/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:36:36 by jgengo            #+#    #+#             */
/*   Updated: 2017/01/18 18:05:44 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int			event_key_next(int keycode, t_env *e)
{
	if (keycode == 78)
	{
		e->scale.x -= 1;
		e->scale.y += 1;
	}
	if (keycode == 1)
	{
		e->alt -= 1;
		apply_height(e, -1);
	}
	if (keycode == 6)
		e->color = CZ;
	if (keycode == 7)
		e->color = CX;
	if (keycode == 8)
		e->color = CC;
	if (keycode == 9)
		e->color = CV;
	if (keycode == 11)
		e->color = CB;
	if (keycode == 45)
		e->color = CN;
	draw_again(e);
	return (1);
}

int			event_key(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		e->pos.x += 30;
	if (keycode == 125)
		e->pos.y += 30;
	if (keycode == 123)
		e->pos.x -= 30;
	if (keycode == 126)
		e->pos.y -= 30;
	if (keycode == 13)
	{
		e->alt += 1;
		apply_height(e, 1);
	}
	if (keycode == 69)
	{
		e->scale.x += 1;
		e->scale.y -= 1;
	}
	return (event_key_next(keycode, e));
}

int			event_mouse(int button, int x, int y, t_env *e)
{
	if (button == 1 && x && y)
	{
		if (e->color == CZ)
			e->color = CX;
		else if (e->color == CX)
			e->color = CC;
		else if (e->color == CC)
			e->color = CV;
		else if (e->color == CV)
			e->color = CB;
		else if (e->color == CB)
			e->color = CN;
		else
			e->color = CZ;
		draw_again(e);
	}
	return (1);
	return (1);
}
