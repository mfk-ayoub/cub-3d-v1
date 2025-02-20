/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:03:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/20 06:48:16 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



double	get_horizontal_intersection(t_cub *cub, t_rays *rays)
{
	float	x_step;
	float	y_step;
	float	inter_x;
	float	inter_y;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(normalize_angle(rays->r_angle));
	inter_x = floor(cub->player_x / TILE_SIZE) * TILE_SIZE;
	inter_y = cub->player_y + (x_step - cub->player_x)
		* tan(normalize_angle(rays->r_angle));
    
    while (!check_if_wall(cub->data,inter_x,inter_x))
    {
        inter_x += x_step;
        inter_y += y_step;
    }
    
}

double	get_vertical_intersection(t_cub *cub, t_rays *rays)
{
	float	x_step;
	float	y_step;
	float	inter_x;
	float	inter_y;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(normalize_angle(rays->r_angle));
	inter_x = floor(cub->player_x / TILE_SIZE) * TILE_SIZE;
	inter_y = cub->player_y + (x_step - cub->player_x)
		* tan(normalize_angle(rays->r_angle));

    while (!check_if_wall(cub->data,inter_x,inter_x))
    {
        inter_x += x_step;
        inter_y += y_step;
    }
    
}

void	rays_data(t_cub *cub, t_rays *rays)
{
	rays->p_x = cub->player_x;
	rays->p_y = cub->player_y;
	rays->h_inter = get_horizontal_intersection(cub, rays);
	rays->v_inter = get_vertical_intersection(cub, rays);
}

void	render_wall(t_cub *cub, t_data *data, t_texture *texture, t_rays *rays)
{
    

    
}
int	ray_casting(t_cub *cub, t_data *data, t_texture *texture, t_rays *rays)
{
	int	i;

	i = -1;
	rays->r_angle = cub->p_angle - (FOV / 2);
	while (++i < NUM_RAYS)
	{
		rays_data(cub, rays);
		if (rays->h_inter <= rays->v_inter)
			rays->distance = rays->h_inter;
		else
			rays->distance = rays->v_inter;
		render_wall(cub, data, texture, rays);
        rays->r_angle +=  FOV / NUM_RAYS;
	}
}

