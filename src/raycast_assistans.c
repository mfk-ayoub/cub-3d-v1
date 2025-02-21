/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_assistans.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:42:05 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/21 03:34:46 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}

void	adjust_x_step(double angle, float *x_step)
{
	if ((angle > PI / 2 && angle < 3 * PI / 2 && *x_step > 0) || ((angle <= PI
				/ 2 || angle >= 3 * PI / 2) && *x_step < 0))
		*x_step *= -1;
}

void	adjust_y_step(double angle, float *y_step)
{
	if ((angle > 0 && angle < PI && *y_step < 0) || (angle > PI && *y_step > 0))
		*y_step *= -1;
}

int	check_vertical_intersection(double angle, float *x_step, float *inter_x)
{
	if (angle > PI / 2 && angle < (3 * PI) / 2)
	{
		*inter_x -= TILE_SIZE;
		*x_step *= -1;
		return (-1);
	}
	return (1);
}

int	check_horizontal_intersection(double angle, float *y_step, float *inter_y)
{
	if (angle > 0 && angle < PI)
	{
		*inter_y += TILE_SIZE;
		return (-1);
	}
	*y_step *= -1;
	return (0);
}
