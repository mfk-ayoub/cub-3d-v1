/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:03:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/21 04:57:08 by ayel-mou         ###   ########.fr       */
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
    (void)texture;
    (void)data;
    double wall_height;
    int top_pixel;
    int bottom_pixel;
    int y;
    int color;

    // Calculate wall height with fisheye correction
    wall_height = (TILE_SIZE / (rays->distance * cos(normalize_angle(rays->r_angle - cub->p_angle)))) *
                  ((WIDTH / 2) / tan(FOV));
    top_pixel = (int)(HEIGHT / 2 - wall_height / 2);
    bottom_pixel = (int)(HEIGHT / 2 + wall_height / 2);

    // Clamp wall bounds to screen
    if (top_pixel < 0)
        top_pixel = 0;
    if (bottom_pixel > HEIGHT)
        bottom_pixel = HEIGHT;

    // Choose wall color based on intersection type
    if (rays->flag == 1) // Horizontal
        color = 0xFF0000; // Red
    else // Vertical
        color = 0x0000FF; // Blue

    // Draw the wall with a solid color using the fixed put_pixel
    for (y = top_pixel; y < bottom_pixel; y++)
        put_pixel(cub, rays->ray_id, y, color);

    // Draw floor and ceiling (optional for visualization)
    for (y = 0; y < top_pixel; y++)
        put_pixel(cub, rays->ray_id, y, 0x89CFF3); // Light blue ceiling
    for (y = bottom_pixel; y < HEIGHT; y++)
        put_pixel(cub, rays->ray_id, y, 0xB99470); // Brown floor
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
