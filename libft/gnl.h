/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:08:51 by jgengo            #+#    #+#             */
/*   Updated: 2016/12/21 08:30:54 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 100

typedef struct				s_fbuffer
{
	int						fd;
	char					*data;
}							t_fbuffer;

int							get_next_line(const int fd, char **line);

#endif
