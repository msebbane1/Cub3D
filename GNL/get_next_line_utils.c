/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:23:48 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/20 13:13:31 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_1;
	int		len_2;
	char	*str;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_1 = gnl_strlen(s1);
	len_2 = gnl_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
		str[len_1++] = s2[i++];
	str[len_1] = '\0';
	return (str);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*m_zero;

	m_zero = malloc(count * size);
	if (m_zero == NULL)
		return (NULL);
	gnl_bzero(m_zero, size * count);
	return (m_zero);
}

void	gnl_bzero(void *s, size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *)s;
	i = 0;
	while (i < n)
	{
		*dest = 0;
		i++;
		dest++;
	}
}

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
