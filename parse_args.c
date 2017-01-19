/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:04:48 by jgengo            #+#    #+#             */
/*   Updated: 2017/01/19 10:24:22 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int		count_words(const char *line)
{
	int		count;
	int		i;
	int		len;
	char	lastchar;

	i = 0;
	count = 0;
	len = ft_strlen(line);
	if (len > 0)
		lastchar = line[0];
	while (i <= len)
	{
		if ((line[i] == ' ' || line[i] == '\0') && lastchar != ' ')
			count++;
		lastchar = line[i];
		i++;
	}
	return (count);
}

static int		get_info(char *filepath, int c)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = open(filepath, O_RDONLY);
	if (c == 1)
	{
		while (get_next_line(fd, &line) > 0)
			ret++;
		close(fd);
	}
	else
	{
		get_next_line(fd, &line);
		ret = count_words(line);
		while (get_next_line(fd, &line) > 0)
		{
			if (count_words(line) != ret)
				exit_error(1);
		}
		close(fd);
	}
	return (ret);
}

void			parse_args(char *filepath, t_env *env)
{
	int index;

	index = 0;
	env->height = get_info(filepath, 1);
	env->width = get_info(filepath, 2);
	env->map = (t_point **)malloc(sizeof(t_point *) * env->height);
	while (index < env->height)
	{
		env->map[index] = (t_point *)malloc(sizeof(t_point) * env->width);
		index++;
	}
}

static void		smallest(t_env *e, int x, int y, int c)
{
	size_t tmp;

	if (c == 0)
	{
		tmp = ft_abs(e->map[y][x].z);
		if ((!e->smallest && tmp != 0) || (e->smallest > tmp && tmp != 0))
			e->smallest = tmp;
	}
	else
	{
		if (!e->smallest)
			e->smallest = 1;
		while (y < e->height)
		{
			while (x < e->width)
			{
				e->map[y][x].z /= e->smallest;
				e->map[y][x].z0 /= e->smallest;
				x++;
			}
			x = 0;
			y++;
		}
	}
}

void			read_args(char *filepath, t_env *env)
{
	int		fd;
	char	*line;
	char	**line_split;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		line_split = ft_strsplit(line, ' ');
		while (*line_split != NULL)
		{
			env->map[y][x].z = ft_atoi(*line_split);
			smallest(env, x, y, 0);
			env->map[y][x].z0 = env->map[y][x].z;
			x++;
			line_split++;
		}
		x = 0;
		y++;
	}
	close(fd);
	smallest(env, 0, 0, 1);
}
