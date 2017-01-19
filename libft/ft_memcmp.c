/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:35:51 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/07 14:11:25 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*r1;
	unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while (n--)
	{
		if (r1[i] != r2[i])
			return (r1[i] - r2[i]);
		i++;
	}
	return (0);
}
