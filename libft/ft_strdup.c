/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:35:35 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/06 23:01:49 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ret;

	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) != NULL)
	{
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
