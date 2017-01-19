/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:29:47 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/09 16:26:39 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char *r;

	r = (char *)malloc(sizeof(char) * size);
	if (r)
	{
		ft_memset(r, 0, size);
		return (r);
	}
	return (0);
}
