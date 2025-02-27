/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:03:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/27 13:30:37 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update(t_cub *cub, t_data *data, t_rays *rays)
{
	double	angle;

	angle = normalize_angle(rays->r_angle);
	rays->mapx = (int)cub->player_x;
	rays->mapy = (int)cub->player_y;
	rays->dirx = cos(angle);
	rays->diry = sin(angle);
	get_delta(rays);
	get_steps_side_dis(rays, cub);
	get_distance_to_wall(rays, data, cub);
	if (rays->side == 0)
		rays->wall_x = cub->player_y + rays->distance * rays->diry;
	else
		rays->wall_x = cub->player_x + rays->distance * rays->dirx;
	rays->wall_x -= floor(rays->wall_x);
}

void	get_wall_data(t_rays *rays, t_cub *cub)
{
	rays->w_height = (double)HEIGHT / (rays->distance * cos(cub->p_angle - rays->r_angle));
	rays->w_top = ((double)HEIGHT / 2) - (rays->w_height / 2);
	rays->w_bottom = ((double)HEIGHT / 2) + (rays->w_height / 2);
	if (rays->w_bottom >= HEIGHT)
		rays->w_bottom = HEIGHT - 1;
}

void	calculate_texture_coords(t_rays *rays, t_mlx *img, int i, t_wall *wall)
{
	if (rays->w_height > 0)
		wall->step = (double)img->height / rays->w_height;
	else
		wall->step = 1.0;
	if (i >= rays->w_top)
		wall->tex_pos = (i - rays->w_top) * wall->step;
	else
		wall->tex_pos = 0;
	wall->tex_y = (int)wall->tex_pos;
	if (wall->tex_x < 0)
		wall->tex_x = 0;
	else if (wall->tex_x >= img->width)
		wall->tex_x = img->width - 1;
	if (wall->tex_y < 0)
		wall->tex_y = 0;
	else if (wall->tex_y >= img->height)
		wall->tex_y = img->height - 1;
}

void	rendring_all(t_cub *cub, t_texture *texture, t_rays *rays)
{
	int		i;
	t_mlx	*img;
	t_wall	wall;

	i = -1;
	texture->f_color = get_colors(texture->rgb->f);
	texture->c_color = get_colors(texture->rgb->c);
	get_wall_data(rays,cub);
	while (++i < rays->w_top)
		put_pixel(cub, rays->ddi, i, texture->c_color);
	img = get_texture_side(rays, cub);
	wall.tex_x = (int)(rays->wall_x * (double)img->width);
	while (i <= rays->w_bottom)
	{
		calculate_texture_coords(rays, img, i, &wall);
		wall.color = get_pixel_color(*img, wall.tex_x, wall.tex_y);
		put_pixel(cub, rays->ddi, i, wall.color);
		i++;
	}
	while (i < HEIGHT)
		put_pixel(cub, rays->ddi, i++, texture->f_color);
}

int	ray_casting(t_cub *cub, t_data *data, t_texture *texture, t_rays *rays)
{
	rays->ddi = 0;
	rays->r_angle = cub->p_angle - (FOV / 2);
	while (rays->ddi < NUM_RAYS)
	{
		update(cub, data, rays);
		rendring_all(cub, texture, rays);
		rays->ddi++;
		rays->r_angle += (FOV / NUM_RAYS);
	}
	return (0);
}
