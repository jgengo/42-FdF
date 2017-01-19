/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:27:10 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/09 16:24:05 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t len;

	if (*little == '\0')
		return ((char *)big);
	len = ft_strlen(little);
	while (*big && len <= n--)
	{
		if (!ft_strncmp(big, little, len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
