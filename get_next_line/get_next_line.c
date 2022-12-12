/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:20:39 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/24 11:36:20 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	ch;

	i = 0;
	str = (char *)s;
	ch = (unsigned char)c;
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] == ch)
	{
		return (str + i);
	}
	return (0);
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	freestr(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

ssize_t	exit_scan(char **stock, ssize_t exit, char **line)
{
	char	*temp;

	if (exit == 0)
	{
		*line = ft_strdup2(*stock);
		freestr(stock);
		return (0);
	}
	else if (exit > 0)
	{
		*line = ft_substr(*stock, 0, (ft_strchr(*stock, '\n') - *stock));
		temp = ft_strdup2(*stock + (ft_strlen2(*line) + 1));
		freestr(stock);
		*stock = temp;
		return (1);
	}
	else
		return (-1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		exit;
	static char *stock = NULL;
	char		buf[2];
	char		*temp;

	if (read(fd, buf, 0) < 0 || !line)
		return (-1);
	if (!stock)
		stock = ft_calloc(1, 1);
	exit = 1;
	while (!ft_strchr(stock, '\n') && exit > 0)
	{
		exit = read(fd, buf, 1);
		buf[exit] = '\0';
		temp = ft_strjoin(stock, buf);
		freestr(&stock);
		stock = temp;
	}
	exit = exit_scan(&stock, exit, line);
	if (exit == 0)
		return (0);
	else if (exit > 0)
		return (1);
	return (-1);
}
