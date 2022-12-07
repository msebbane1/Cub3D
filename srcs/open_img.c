/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:04:48 by msebbane          #+#    #+#             */
/*   Updated: 2022/12/07 15:09:20 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_texture_path(char	*path)
{
	int		fd;
	int		fd2;

	fd = 0;
	fd = open(path, O_RDONLY);
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
	cub->map.texture[0] = init_img(cub->mlx, cub->map.path_no);
	cub->map.texture[1] = init_img(cub->mlx, cub->map.path_so);
	cub->map.texture[2] = init_img(cub->mlx, cub->map.path_we);
	cub->map.texture[3] = init_img(cub->mlx, cub->map.path_ea);
}
