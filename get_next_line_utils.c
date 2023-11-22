/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapima <gapima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:12:52 by gapima            #+#    #+#             */
/*   Updated: 2023/11/22 16:39:48 by gapima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
    size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (*s1)
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		result[i] = *s2;
		s2++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strrchr(char const *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len)
	{
		if (s[len] == (unsigned char)c)
		{
			return ((char *)&s[len]);
		}
		len--;
	}
	if (s[len] == (unsigned char)c)
	{
		return ((char *)&s[len]);
	}
	return (NULL);
}

