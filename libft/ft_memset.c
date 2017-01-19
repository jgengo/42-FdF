/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:14:16 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/11 09:41:05 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *ptr, int value, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		((char *)ptr)[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
