/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <glima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:01:33 by glima             #+#    #+#             */
/*   Updated: 2023/11/27 10:25:06 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		count;

	i = 0;
	count = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[count])
	{
		result[i] = s2[count];
		count++;
		i++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*ft_strrchr(char *s, int c)
{
	int		len;

	if (!s)
		return (NULL);
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
		return ((char *)&s[len]);
	return (NULL);
}
