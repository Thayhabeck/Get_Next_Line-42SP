/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:40:12 by thabeck-          #+#    #+#             */
/*   Updated: 2022/05/12 16:46:36 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*accumulator;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulator = ft_set_accumulator(fd, accumulator);
	if (!accumulator)
		return (NULL);
	line = ft_get_line(accumulator);
	accumulator = ft_new_accumulator(accumulator);
	return (line);
}
