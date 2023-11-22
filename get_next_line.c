/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapima <gapima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:44:15 by gapima            #+#    #+#             */
/*   Updated: 2023/11/22 17:28:31 by gapima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_get_line(int fd, char *str)
{
	char	*temp;
	int		temp_len;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	temp_len = 1;
	while (ft_strrchr(str, '\n') == NULL)
	{
		temp_len = read(fd, temp, BUFFER_SIZE);
		if (temp_len < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[temp_len] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

static char	*ft_current_line(char *str, char *line)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
		return (NULL);
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\n')
		line = malloc((count + 2) * sizeof(char));
	else if (str[count] == '\0')
		line = malloc((count + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	count = -1;
	while (str[++count] != '\n' && str[count] != '\0')
		line[count] = str[count];
	if (str[count] == '\n')
		line[count++] = '\n';
	line[count] = '\0';
	return (line);
}

static char    *get_next_line(int fd)
{
    static char		*next_line;
	char			*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = ft_get_line(fd, next_line);
	if (next_line == NULL)
		return (NULL);
	current_line = NULL;
	current_line = ft_current_line(next_line, current_line);
}