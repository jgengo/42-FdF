/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:35:31 by jgengo            #+#    #+#             */
/*   Updated: 2017/01/18 18:09:14 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# include <mlx.h>
# include <math.h>

# define WIN_X 1000
# define WIN_Y 1000
# define CZ 0xFFFFFF
# define CX 0x0E50BA
# define CC 0xC60707
# define CV 0x8c0fc6
# define CB 0xe8930b
# define CN 0x04963e

typedef struct			s_point
{
	int					z;
	int					z0;
	int					xp;
	int					yp;
}						t_point;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_point				**map;
	t_coord				scale;
	t_coord				pos;
	int					height;
	int					width;
	int					alt;
	size_t				smallest;
	int					color;
}						t_env;

void					check_args(int ac);
void					parse_args(char *filepath, t_env *env);
void					read_args(char *filepath, t_env *env);
void					exit_error(int c);
void					apply_proj(t_env *env);
void					apply_height(t_env *e, int c);
void					draw_lines(t_env *env, int x, int y);
void					pixel_put(t_env *e, int x, int y, int color);
void					draw_again(t_env *e);
int						event_mouse(int button, int x, int y, t_env *env);
int						event_key(int keycode, t_env *env);
#endif
