/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:23:46 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/31 12:12:00 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t count, size_t size);
void	gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *s);
char	*get_next_line(int fd, char **sasoule);

#endif