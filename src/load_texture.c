/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:44:56 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 00:44:32 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_mlx	load_texture(t_cub *cub, char *texture_path)
{
	t_mlx	texture;

	texture.img = mlx_xpm_file_to_image(cub->mlx, texture_path, &texture.width,
			&texture.height);
	if (!texture.img)
	{
		exit(1);
	}
	texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel,
			&texture.line_length, &texture.endian);
	if (!texture.addr)
	{
		mlx_destroy_image(cub->mlx, texture.img);
		exit(1);
	}
	return (texture);
}

int	get_pixel_color(t_mlx texture, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || x >= texture.width || y < 0 || y >= texture.height)
		return (0);
	pixel = texture.addr + (y * texture.line_length + x
			* (texture.bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

t_mlx	*get_texture_side(t_rays *rays, t_cub *cub)
{
	if (rays->side == 0)
	{
		if (rays->stepx > 0)
			return (&cub->texture->ea_texture);
		return (&cub->texture->we_texture);
	}
	else
	{
		if (rays->stepy > 0)
			return (&cub->texture->so_texture);
		return (&cub->texture->no_texture);
	}
}
