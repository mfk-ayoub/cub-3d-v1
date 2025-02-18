/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathguide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:04:46 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/18 02:24:27 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_circle(t_cub *cub)
{
	int	center_x;
	int	center_y;
	int	r;
	int	x;
	int	y;

	center_x = OFFSET + cub->pixel_size * 4;
	center_y = OFFSET + cub->pixel_size * 4;
	r = cub->pixel_size * 4;
	y = center_y - r - 1;
	while (++y <= center_y + r)
	{
		x = center_x - r - 1;
		while (++x <= center_x + r)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y) * (y
					- center_y) <= r * r)
				put_pixel_to_image(cub->img, x, y, 0x4d5656);
		}
	}
}
int	calculate_pixel_size(t_data *data)
{
	int	pixel_size_w;
	int	pixel_size_h;
	int	minimap_w;
	int	minimap_h;

	minimap_w = WIDTH * SCALE;
	minimap_h = HEIGHT * SCALE;
	pixel_size_w = minimap_w / data->col;
	pixel_size_h = minimap_h / data->row;
	return (fmin(pixel_size_w, pixel_size_h));
}

void	put_pixel(t_cub *cub, double map_x, double map_y, int color)
{
	int		i;
	int		j;
	int		center_x;
	int		center_y;
	double	i_x;
	double	i_y;
	double	new_x;
	double	new_y;
	double	distance;

	center_x = OFFSET + cub->pixel_size * 4;
	center_y = OFFSET + cub->pixel_size * 4;
	i_x = center_x + (map_x - cub->player_x) * cub->pixel_size;
	i_y = center_y + (map_y - cub->player_y) * cub->pixel_size;
	i = -1;
	while (++i < cub->pixel_size)
	{
		j = -1;
		while (++j < cub->pixel_size)
		{
			new_x = i_x + j;
			new_y = i_y + i;
			distance = (new_x - center_x) * (new_x - center_x) + (new_y
					- center_y) * (new_y - center_y);
			if (distance <= (cub->pixel_size * 4) * (cub->pixel_size * 4))
				put_pixel_to_image(cub->img, new_x, new_y, color);
		}
	}
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

void	path_guide(t_cub *cub, t_data *data)
{
	int start_x = (int)cub->player_x - 4;
	int start_y = (int)cub->player_y - 4;
	int end_x = (int)cub->player_x + 4;
	int end_y = (int)cub->player_y + 4;
	int y = start_y - 1;
	while (++y <= end_y)
	{
		int x = start_x - 1;
		while (++x <= end_x)
		{
			if (y >= 0 && y < data->row && x >= 0 && x < data->col)
			{
				if (data->map[y][x] == '1')
					put_pixel(cub, x, y, 0x0000df0);
				else if (data->map[y][x] == '0')
					put_pixel(cub, x, y, 0x00ffdf0);
				else
					draw_player(cub,start_x,start_y,0x55fdf1);
			}
		}
	}
}
