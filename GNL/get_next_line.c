/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:23:44 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/31 13:15:04 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1

char	*ft_next(char *buffer);
char	*ft_free(char *buffer, char *buf);
char	*read_file(int fd, char *res);
char	*ft_line(char *buffer);

char	*get_next_line(int fd, char **line)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	*line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (*line);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = gnl_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = gnl_calloc((sizeof(char)), gnl_strlen(buffer) - i + 1);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = gnl_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = gnl_calloc(1, 1);
	buffer = gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}
