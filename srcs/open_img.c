/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:04:48 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 15:22:54 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_file(char	*path)
{
	int		fd;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (1);
	if (read(fd, &c, 1) <= 0)
		return (1);
	close(fd);
	return (0);
}

t_img	init_img(void	*mlx, char *path)
{
	t_img	img;

	//check_texture_path(path); //A remettre avec les vrai texture
	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	return (img);
}
