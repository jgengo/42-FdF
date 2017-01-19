/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgengo <jgengo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:40:53 by jgengo            #+#    #+#             */
/*   Updated: 2016/11/10 09:57:18 by jgengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	char		*ret;
	int			j;

	start = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	while (ft_isblank(s[start]) || s[start] == '\n')
	{
		start++;
		if (s[start] == '\0')
			j = 1;
	}
	while (j == 0 && (ft_isblank(s[end - 1]) || s[end - 1] == '\n'))
		end--;
	ret = ft_strnew(end - start);
	if (ret == NULL)
		return (NULL);
	return (ft_strncpy(ret, s + start, end - start));
}
