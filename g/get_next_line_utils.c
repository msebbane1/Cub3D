/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:21:11 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/24 11:36:49 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup2(const char *s)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen2(s);
	dest = (char *) malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size_s;

	i = 0;
	size_s = ft_strlen2(s);
	if (!s)
		return (NULL);
	if (size_s <= start)
		return (ft_strdup2(""));
	if (size_s < len)
		len = size_s;
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (start < size_s && i < len && i + start < size_s)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen2(s1);
	size_s2 = ft_strlen2(s2);
	join = (char *) malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!join)
		return (NULL);
	*join = 0;
	ft_strcat(join, s1);
	ft_strcat(join, s2);
	return (join);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	total;

	total = count * size;
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (total));
	return (str);
}
