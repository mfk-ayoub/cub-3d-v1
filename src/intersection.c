/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 05:39:09 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/22 02:47:10 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


double get_horizontal_intersection(t_cub *cub, t_rays *rays)
{
    t_horizontal horizontal;

    ft_memset(&horizontal, 0, sizeof(t_horizontal));
    horizontal.angle = normalize_angle(rays->r_angle);
    horizontal.y_step = TILE_SIZE;
    horizontal.x_step = TILE_SIZE / tan(horizontal.angle);
    horizontal.inter_y = floor(cub->player_y / TILE_SIZE) * TILE_SIZE;
    horizontal.direction = check_horizontal_intersection(horizontal.angle, &horizontal.y_step, &horizontal.inter_y);
    horizontal.inter_x = cub->player_x + (horizontal.inter_y - cub->player_y) / tan(horizontal.angle);
    adjust_x_step(horizontal.angle, &horizontal.x_step);
    while (!check_if_wall(cub->data, horizontal.inter_x, horizontal.inter_y - horizontal.direction))
    {
        horizontal.inter_x += horizontal.x_step;
        horizontal.inter_y += horizontal.y_step;
    }
    rays->dx = horizontal.inter_x;
    rays->dy = horizontal.inter_y;
    rays->flag = 0;
    return (calculate_distance(horizontal.inter_x, cub->player_x, horizontal.inter_y, cub->player_y));
}

double get_vertical_intersection(t_cub *cub, t_rays *rays)
{
    t_vertical vertical;

    ft_memset(&vertical, 0, sizeof(t_vertical));
    vertical.angle = normalize_angle(rays->r_angle);
    vertical.x_step = TILE_SIZE;
    vertical.y_step = TILE_SIZE * tan(vertical.angle);
    vertical.inter_x = floor(cub->player_x / TILE_SIZE) * TILE_SIZE;
    vertical.direction = check_vertical_intersection(vertical.angle, &vertical.x_step, &vertical.inter_x);
    vertical.inter_y = cub->player_y + (vertical.inter_x - cub->player_x) * tan(vertical.angle);
    adjust_y_step(vertical.angle, &vertical.y_step);
    while (!check_if_wall(cub->data, vertical.inter_x - vertical.direction, vertical.inter_y))
    {
        vertical.inter_x += vertical.x_step;
        vertical.inter_y += vertical.y_step;
    }
    rays->dx = vertical.inter_x;
    rays->dy = vertical.inter_y;
    rays->flag = 1;
    return (calculate_distance(vertical.inter_x, cub->player_x, vertical.inter_y, cub->player_y));
}
