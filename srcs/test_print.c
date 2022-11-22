/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:22:14 by msebbane          #+#    #+#             */
/*   Updated: 2022/11/22 17:13:33 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	test_print(t_cub *cub)
{
	int		i;

	i = 0;
	printf("size line = %d\n", cub->map.size.y);
	printf("cub->map.index = %d\n", cub->map.index);
	printf("cub->map.index_spaces = %d\n", cub->map.index_spaces);
	while (cub->map.str[i])
		printf("[PRINT]line = %s\n", cub->map.str[i++]);
}