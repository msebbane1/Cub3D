/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:04:48 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/12 16:46:11 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_fd(int fd, int fd2, int *error)
{
	char	c;

	if (fd <= 0)
	{
		error_msg("Error\nInvalid texture path : doesn't exist");
		close(fd);
		*error = 1;
	}
	if (fd2 != -1)
	{
		error_msg("Error\nInvalid texture path : Directory");
		close(fd2);
		*error = 1;
	}
	if (read(fd, &c, 1) < 1)
	{
		error_msg("Error\nInvalid Texture : Empty file");
		*error = 1;
	}
	else
		*error = 0;
}

void	check_texture_path(char	*path, int *error)
{
	int		fd;
	int		fd2;

	fd = open(path, O_RDONLY);
	fd2 = open(path, O_DIRECTORY);
	check_fd(fd, fd2, error);
	close(fd);
	close(fd2);
	if (ft_strncmp(".xpm", path + ft_strlen(path) - 4, 4))
	{
		error_msg("Error\nInvalid texture(.xpm)");
		*error = 1;
	}
	else
		*error = 0;
}

t_texture	init_img(void	*mlx, char *path)
{
	t_texture	img;
	int			x;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	img.addr = (int *) mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &x);
	return (img);
}

void	open_textures(t_cub *cub)
{
	cub->map.texture[0] = init_img(cub->mlx, cub->map.path_we);
	cub->map.texture[1] = init_img(cub->mlx, cub->map.path_ea);
	cub->map.texture[2] = init_img(cub->mlx, cub->map.path_no);
	cub->map.texture[3] = init_img(cub->mlx, cub->map.path_so);
}
