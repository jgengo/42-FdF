/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:15:04 by jgengo            #+#    #+#             */
/*   Updated: 2017/01/18 11:25:09 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	proj_x(int x, int y, t_env *e)
{
	double ret;

	ret = (M_SQRT2 / 2) * (x - y);
	ret *= e->scale.x;
	return ((int)ret);
}

static int	proj_y(int x, int y, t_env *e)
{
	double ret;

	ret = (sqrt(3 / 2) * e->map[y][x].z);
	ret -= (1 / sqrt(6) * (x + y));
	ret *= e->scale.y;
	return ((int)ret);
}

void		apply_height(t_env *e, int c)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < e->height)
	{
		while (x < e->width)
		{
			if (e->map[y][x].z0 != 0)
			{
				if (c == 1)
					e->map[y][x].z = (e->map[y][x].z0 * e->alt);
				else
					e->map[y][x].z = (e->map[y][x].z0 * e->alt);
				e->map[y][x].xp = proj_x(x, y, e);
				e->map[y][x].yp = proj_y(x, y, e);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void		apply_proj(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < e->height)
	{
		while (x < e->width)
		{
			e->map[y][x].xp = proj_x(x, y, e);
			e->map[y][x].yp = proj_y(x, y, e);
			x++;
		}
		x = 0;
		y++;
	}
}
