/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:21 by lbally            #+#    #+#             */
/*   Updated: 2022/10/16 18:37:46 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*get_content(char *content)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!content)
		return (0);
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (0);
	}
	rest = malloc(sizeof(char) * (ft_strlen(content) - i) + 1);
	if (rest == NULL)
		return (0);
	i++;
	while (content[i])
		rest[j++] = content[i++];
	rest[j] = '\0';
	free(content);
	return (rest);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_read(int fd, char **content, int ret, char *buff)
{
	while (!has_return(*content) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		*content = join_str(*content, buff);
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*content;
	int				ret;

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	ret = ft_read(fd, &content, ret, buff);
	if (ret == -1)
		return (-1);
	free(buff);
	*line = get_line(content);
	content = get_content(content);
	if (ret == 0)
		return (0);
	return (1);
}
