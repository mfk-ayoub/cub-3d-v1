/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:32:27 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/20 05:13:20 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calculate_distance(double x1, double x2, double y1, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

int	check_if_wall(t_data *data, t_rays *rays)
{
	int	map_x;
	int	map_y;

	map_y = (int)(rays->r_y / TILE_SIZE);
	map_x = (int)(rays->r_x / TILE_SIZE);
	if (map_x < 0 || map_x >= data->col || map_y < 0 || map_y >= data->row)
		return (1);
	if (data->map[map_y][map_x] == '1')
		return (1);
	return (0);
}
