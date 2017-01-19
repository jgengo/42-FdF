/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:09:04 by jgengo            #+#    #+#             */
/*   Updated: 2017/01/18 17:10:53 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_args(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("You did not pass the right number of arguments.\n", 2);
		ft_putstr_fd("Usage: ./fdf file.fdf\n", 2);
		exit(0);
	}
}

void		exit_error(int c)
{
	if (c == 1)
		ft_putstr_fd("Error: Map is invalid.\n", 2);
	if (c == 2)
		ft_putstr_fd("Error: mlx failed.\n", 2);
	exit(0);
}
