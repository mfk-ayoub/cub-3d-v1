/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:03:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/25 04:19:08 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void rays_debug(t_rays *rays)
{
	printf(" ray distance %f\n",rays->distance);
	printf(" ray ddi %d\n",rays->ddi);
	printf("rays stepx %d and stepy %d\n",rays->stepx, rays->stepy);
	printf("rays sidesdisx %f and sidedisy %f\n",rays->side_dist_x, rays->side_dist_y);
	printf("rays mapx %d and mapy %d\n",rays->mapx, rays->mapy);
	printf("rays dirx %f and diry %f\n",rays->diry, rays->diry);
	printf(" ray angle %f\n",rays->r_angle);
}
void	get_distance_to_wall(t_rays *rays, t_data *data, t_cub *cub)
{
	rays->find_wall = 0;
    while (!rays->find_wall)
    {
        if (rays->side_dist_x < rays->side_dist_y)
        {
            rays->side_dist_x += rays->deltax;
            rays->mapx += rays->stepx;
            rays->side = 0;
        }
        else
        {
            rays->side_dist_y += rays->deltay;
            rays->mapy += rays->stepy;
            rays->side = 1;
        }
        if (rays->mapx < 0 || rays->mapx >= data->col ||
            rays->mapy < 0 || rays->mapy >= data->row)
        {
            rays->find_wall = 1;
            break;
        }
        if (data->map[rays->mapy][rays->mapx] == '1')
            rays->find_wall = 1;
    }
	if (rays->side == 0)
    	rays->distance = (rays->mapx - cub->player_x + (1 - rays->stepx) / 2) / rays->dirx;
	else
    	rays->distance = (rays->mapy - cub->player_y + (1 - rays->stepy) / 2) / rays->diry;
	rays->distance *= cos(cub->p_angle - rays->r_angle);
	
}

void get_delta(t_rays *rays)
{
    if (rays->dirx == 0 && rays->diry == 0) 
    {
        rays->dirx = 0.00001;
        rays->diry = 0.00001;
    }
    if (rays->dirx == 0)
        rays->deltax = INFINITY; 
    else
        rays->deltax = fabs(1 / rays->dirx);

    if (rays->diry == 0)
        rays->deltay = INFINITY; 
    else
        rays->deltay = fabs(1 / rays->diry);
}



void	get_steps_side_dis(t_rays *rays, t_cub *cub)
{
	if (rays->dirx < 0)
	{
		rays->stepx = -1;
		rays->side_dist_x = (cub->player_x - rays->mapx) * rays->deltax;
	}
	else
	{
		rays->stepx = 1;
		rays->side_dist_x = (rays->mapx + 1.0 - cub->player_x) * rays->deltax;
	}
	if (rays->diry < 0)
	{
		rays->stepy = -1;
		rays->side_dist_y = (cub->player_y - rays->mapy) * rays->deltay;
	}
	else
	{
		rays->stepy = 1;
		rays->side_dist_y = (rays->mapy + 1.0 - cub->player_y) * rays->deltay;
	}
}

void	update(t_cub *cub, t_data *data, t_rays *rays)
{
	rays->mapx = (int)cub->player_x;
	rays->mapy = (int)cub->player_y;
	
	rays->dirx = cos(rays->r_angle);
	rays->diry = sin(rays->r_angle);
	get_delta(rays);
	get_steps_side_dis(rays, cub);
	get_distance_to_wall(rays, data, cub);
	if (rays->side == 0)
    	rays->wall_x = cub->player_y + rays->distance * rays->diry;
	else
		rays->wall_x = cub->player_x + rays->distance * rays->dirx;
	rays->wall_x -= floor(rays->wall_x); 
	// rays_debug(rays);
}

t_mlx *get_texture_side(t_rays *rays, t_cub *cub)
{
	t_mlx *texture;

	if (rays->side == 0)
	{
		if (rays->stepx > 0)
			texture = &cub->texture->ea_texture; 
		else
			texture = &cub->texture->we_texture; 
	}
	else
	{
		if (rays->stepy > 0)
			texture = &cub->texture->so_texture; 
		else
			texture = &cub->texture->no_texture;
	}
	return (texture);

}

void get_wall_data(t_cub *cub, t_texture *texture, t_rays *rays)
{
	
	(void)texture;
	(void)cub;
    rays->w_height = (double)HEIGHT / rays->distance;
    rays->w_top = ((double)HEIGHT / 2) - (rays->w_height / 2);
    rays->w_bottom = ((double)HEIGHT / 2) + (rays->w_height / 2);

    if (rays->w_top < 0)
        rays->w_top = 0;
    if (rays->w_bottom >= HEIGHT)
        rays->w_bottom = HEIGHT - 1;

}

void rendring_all(t_cub *cub, t_texture *texture, t_rays *rays)
{
	int  i;

	i = -1;
	// t_mlx		*img;
	texture->f_color = get_colors(texture->rgb->f);
	texture->c_color = get_colors(texture->rgb->c);
	get_wall_data(cub, texture, rays);
	while (++i < rays->w_top)
		put_pixel(cub,rays->ddi,i,texture->c_color);	

	while (i <= rays->w_bottom)
		// int color = get_pixel_color(img,rays->ddi,i)
		put_pixel(cub, rays->ddi, i++, 0x505050);

	while (++i < HEIGHT)
		put_pixel(cub,rays->ddi,i,texture->f_color);
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

