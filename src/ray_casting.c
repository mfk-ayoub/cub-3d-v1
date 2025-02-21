/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:03:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/21 05:37:38 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void rays_data(t_cub *cub, t_rays *rays)
{
    rays->p_x = cub->player_x;
    rays->p_y = cub->player_y;
    rays->h_inter = get_horizontal_intersection(cub, rays);
    rays->v_inter = get_vertical_intersection(cub, rays);
}

void render_wall(t_cub *cub, t_data *data, t_texture *texture, t_rays *rays)
{
	t_wall wall;

	ft_memset(&wall,0,sizeof(wall));
	wall.w_height = 
}

int ray_casting(t_cub *cub, t_data *data, t_texture *texture, t_rays *rays)
{
    int i;

    i = -1;
    rays->r_angle = cub->p_angle - (FOV / 2);
    rays->ray_id = 0;
    while (++i < NUM_RAYS)
    {
        rays_data(cub, rays);
        if (rays->h_inter <= rays->v_inter)
            rays->distance = rays->h_inter;
        else
        {
            rays->flag = 1;
            rays->distance = rays->v_inter;
        }
        render_wall(cub, data, texture, rays);
        rays->r_angle += FOV / NUM_RAYS;
        rays->ray_id++;
    }
    return (0);
}
