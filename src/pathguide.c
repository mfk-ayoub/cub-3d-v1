/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathguide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:04:46 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/19 00:39:58 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int calculate_pixel_size(t_data *data)
{
    int pixel_size_w;
    int pixel_size_h;
    int minimap_w;
    int minimap_h;

    minimap_w = WIDTH * SCALE;
    minimap_h = HEIGHT * SCALE;
    pixel_size_w = minimap_w / data->row;
    pixel_size_h = minimap_h / data->col;
    return (fmin(pixel_size_w, pixel_size_h)); 
}

void	draw_player(t_cub *cub, int px, int py, int color)
{
	int	x;
	int	y;

	y = -RADIUS;
	while (y <= RADIUS)
	{
		x = -RADIUS;
		while (x <= RADIUS)
		{
			if ((x * x) + (y * y) <= RADIUS * RADIUS)
				put_pixel_to_image(cub->img, px + x, py + y, color);
			x++;
		}
		y++;
	}
}

void put_pixel(t_cub *cub, double map_x, double map_y, int color)
{
    int i = 0;
    int j;
    double new_x;
    double new_y;

    while (i < cub->pixel_size)
    {
        j = 0;
        while (j < cub->pixel_size)
        {
            new_x = map_x + j;
            new_y = map_y + i;
            put_pixel_to_image(cub->img, new_x, new_y, color);
            j++;
        }
        i++;
    }
}

void path_guide(t_cub *cub, t_data *data)
{
    int y;
    int x;
    
	y = 0;
    while (y < data->row)
    {
        x = 0;
        while (x < data->col)
        {
            if (data->map[y][x] == '1')
                put_pixel(cub, x * cub->pixel_size, y * cub->pixel_size, 0x7f8c8d);
            else
                put_pixel(cub, x * cub->pixel_size, y * cub->pixel_size, 0x4d5656);
            x++;
        }
        y++;
    }
}
