/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:09:06 by thabeck-          #+#    #+#             */
/*   Updated: 2022/05/13 00:27:28 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_set_accumulator(int fd, char *accumulator)
{
	char	*buffer;
	ssize_t	file_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	file_bytes = 1;
	while (!ft_strchr(accumulator, '\n') && file_bytes)
	{
		file_bytes = read(fd, buffer, BUFFER_SIZE);
		if (file_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[file_bytes] = '\0';
		accumulator = ft_strjoin(accumulator, buffer);
	}
	free(buffer);
	return (accumulator);
}

char	*ft_get_line(char *accumulator)
{
	int		i;
	char	*line;

	i = 0;
	if (!accumulator[i])
		return (NULL);
	while (accumulator[i] && accumulator[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (accumulator[i] && accumulator[i] != '\n')
	{
		line[i] = accumulator[i];
		i++;
	}
	if (accumulator[i] == '\n')
	{
		line[i] = accumulator[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_accumulator(char *accumulator)
{
	int		i;
	int		j;
	char	*new_acc;

	i = 0;
	while (accumulator[i] && accumulator[i] != '\n')
		i++;
	if (!accumulator[i])
	{
		free(accumulator);
		return (NULL);
	}
	j = ft_strlen(accumulator) - i + 1;
	new_acc = (char *)malloc(sizeof(char) * j);
	if (!new_acc)
		return (NULL);
	i++;
	j = 0;
	while (accumulator[i])
		new_acc[j++] = accumulator[i++];
	new_acc[j] = '\0';
	free(accumulator);
	return (new_acc);
}

char	*get_next_line(int fd)
{
	static char	*accumulator[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulator[fd] = ft_set_accumulator(fd, accumulator[fd]);
	if (!accumulator[fd])
		return (NULL);
	line = ft_get_line(accumulator[fd]);
	accumulator[fd] = ft_new_accumulator(accumulator[fd]);
	return (line);
}
