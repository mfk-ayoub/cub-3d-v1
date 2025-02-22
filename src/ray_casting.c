/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:03:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/22 02:46:48 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"




void	draw_floor_ceiling(t_cub *cub,t_rays *rays, t_rgb *rgb, t_wall *wall)
{
	int f_rgb;
	int c_rgb;
	int x;
	
	f_rgb = get_colors(rgb->f);
	c_rgb = get_colors(rgb->c);
	x = wall->w_bottom;
	while (x < HEIGHT)
		put_pixel(cub, rays->ray_id, x++, f_rgb);
	x = 0;
	while (x < wall->w_top)
		put_pixel(cub, rays->ray_id, x++, c_rgb); 
}

int	get_color(t_cub *cub, t_rays  *rays)	// get the color of the wall
{
	(void)cub;
	rays->r_angle= normalize_angle(rays->r_angle); // normalize the angle
	if (rays->flag == 0)
	{
		if (rays->r_angle> PI / 2 && rays->r_angle < 3 * (PI / 2))
			return (0xB5B5B5FF); // west wall
		else
			return (0xB5B5B5FF); // east wall
	}
	else
	{
		if (rays->r_angle > 0 && rays->r_angle < PI)
			return (0xF5F5F5FF); // south wall
		else
			return (0xF5F5F5FF); // north wall
	}
}

void rendring_wall(t_cub *cub, t_rays *rays, t_wall *wall)
{
    int y = wall->w_top;
	int color;

	color = get_color(cub,rays);
    while (y < wall->w_bottom)
    {
        if (y >= 0 && y < HEIGHT && rays->ray_id >= 0 && rays->ray_id < WIDTH)
            put_pixel(cub, rays->ray_id, y, color); 
        y++;
    }

}

void render_wall(t_cub *cub, t_data *data, t_texture *texture, t_rays *rays)
{
    (void)data;
    t_wall wall;
	
    ft_memset(&wall, 0, sizeof(wall));
    wall.proj_dist = rays->distance * cos(rays->r_angle - cub->p_angle);
    if (wall.proj_dist < 0.1)
        wall.proj_dist = 0.1;
    wall.proj_plane_dist = (WIDTH / 2) / tan(FOV / 2); 
    wall.w_height = (TILE_SIZE / wall.proj_dist) * wall.proj_plane_dist;
    if (wall.w_height < 1)
        wall.w_height = 1;
    wall.w_top = (HEIGHT / 2) - (wall.w_height / 2);
    wall.w_bottom = (HEIGHT / 2) + (wall.w_height / 2);
    if (wall.w_top < 0)
        wall.w_top = 0;
    if (wall.w_bottom >= HEIGHT)
        wall.w_bottom = HEIGHT - 1;

    rendring_wall(cub, rays, &wall);
    draw_floor_ceiling(cub, rays, texture->rgb, &wall);
}

int ray_casting(t_cub *cub, t_data *data, t_texture *texture, t_rays *rays)
{
    int i;

    i = -1;
    rays->r_angle = normalize_angle(cub->p_angle - (FOV / 2));
    rays->ray_id = 0;
    while (++i < NUM_RAYS)
    {
        rays->p_x = cub->player_x;
        rays->p_y = cub->player_y;
        rays->h_inter = get_horizontal_intersection(cub, rays);
        rays->v_inter = get_vertical_intersection(cub, rays);
        if (rays->h_inter <= rays->v_inter)
            rays->distance = rays->h_inter;
        else
        {
            rays->flag = 1;
            rays->distance = rays->v_inter;
        }
        render_wall(cub, data, texture, rays);
        rays->r_angle = normalize_angle(rays->r_angle + FOV / NUM_RAYS);
        rays->ray_id++;
    }
    return (0);
}