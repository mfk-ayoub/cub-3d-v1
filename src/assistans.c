/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:42:05 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/04 14:39:10 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define COLLISION_RADIUS 0.2

int	is_wall(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x);
	map_y = (int)(y);
	if (map_x < 0 || map_y < 0 || map_x >= data->col || map_y >= data->row)
		return (1);
	if (data->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}

void	get_delta(t_rays *rays)
{
	if (rays->dirx == 0)
		rays->deltax = INFINITY;
	else
		rays->deltax = fabs(1 / rays->dirx);
	if (rays->diry == 0)
		rays->deltay = INFINITY;
	else
		rays->deltay = fabs(1 / rays->diry);
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
		if (is_wall(data, rays->mapx, rays->mapy))
			rays->find_wall = 1;
	}
	if (rays->side == 0)
		rays->distance = (rays->mapx - cub->player_x + (1 - rays->stepx) / 2)
			/ rays->dirx;
	else
		rays->distance = (rays->mapy - cub->player_y + (1 - rays->stepy) / 2)
			/ rays->diry;
	// rays->distance *= cos(cub->p_angle - rays->r_angle);
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
