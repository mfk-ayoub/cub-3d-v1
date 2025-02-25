/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:44:56 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/25 02:06:08 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



t_mlx load_texture(t_cub *cub, char *texture_path)
{
    t_mlx texture;

    texture.img = mlx_xpm_file_to_image(cub->mlx, texture_path, &texture.width, &texture.height);
    if (!texture.img)
    {
        printf(TEXTURE_FAILD);
        exit(1);
    }

    texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel, &texture.line_length, &texture.endian);
    if (!texture.addr)
    {
        mlx_destroy_image(cub->mlx, texture.img);
        exit(1);
    }

    return texture;
}

int get_pixel_color(t_mlx *texture, int x, int y)
{
    char *pixel;
    int color;

    pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    color = *(int *)pixel;
    return color;
}

