/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:04:48 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/24 11:50:45 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_texture_path(char	*path)
{
	int		fd;
	int		fd2;

	fd = 0;
	fd = open(path, O_RDONLY);
	printf("fd = %d\n", fd);
	printf("path = |%s|\n", path);
	fd2 = open(path, O_DIRECTORY);
	if (fd <= 0)
	{
		error_msg("Error\nInvalid texture : doesn't exist");
		close(fd);
	}
	if (fd2 != -1)
	{
		error_msg("Error\nTexture path invalid :Directory");
		close(fd2);
	}
	close(fd);
	close(fd2);
	if (ft_strncmp(".xpm", path + ft_strlen(path) - 4, 4))
		error_msg("Error\nInvalid texture(.xpm)");
}

t_img	init_img(void	*mlx, char *path)
{
	t_img	img;

	//check_texture_path(path); //A remettre avec les vrai texture
	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	return (img);
	/*img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	return (img);*/
	/*
	else
	{
		img.img = NULL;
		img.addr = NULL;
		return (img);
	}*/
}
