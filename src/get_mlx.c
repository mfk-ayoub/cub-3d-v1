/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:47:30 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/16 18:48:18 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	call_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (1);
	cub->win = mlx_new_window(cub->mlx, WIDTH,HEIGHT, "cub3d");
	if (!cub->win)
		return (1);
	cub->img.img = mlx_new_image(cub->mlx, WIDTH,HEIGHT);
	if (!cub->img.img)
		return (1);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	return (0);
}

