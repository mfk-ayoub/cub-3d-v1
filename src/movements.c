/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:28:12 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/07 00:50:35 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_cub *cub, double *new_x, double *new_y)
{
	double	angle;

	angle = normalize_angle(cub->p_angle);
	*new_x = cub->player_x + (cos(angle) * MOVESTEP);
	*new_y = cub->player_y + (sin(angle) * MOVESTEP);
}

void	move_backward(t_cub *cub, double *new_x, double *new_y)
{
	double	angle;

	angle = normalize_angle(cub->p_angle);
	*new_x = cub->player_x - (cos(angle) * MOVESTEP);
	*new_y = cub->player_y - (sin(angle) * MOVESTEP);
}

void	move_left(t_cub *cub, double *new_x, double *new_y)
{
	double	tmp_x;
	double	tmp_y;
	double	angle;

	angle = normalize_angle(cub->p_angle);
	tmp_x = cos(angle);
	tmp_y = sin(angle);
	*new_x = cub->player_x + (tmp_y * MOVESTEP);
	*new_y = cub->player_y - (tmp_x * MOVESTEP);
}

void	move_right(t_cub *cub, double *new_x, double *new_y)
{
	double	tmp_x;
	double	tmp_y;
	double	angle;

	angle = normalize_angle(cub->p_angle);
	tmp_x = cos(angle);
	tmp_y = sin(angle);
	*new_x = cub->player_x - (tmp_y * MOVESTEP);
	*new_y = cub->player_y + (tmp_x * MOVESTEP);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	int			delta_x;
	static int	last_x;

	(void)y;
	if (last_x == 0)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	if (delta_x > 0)
		cub->p_angle += ROTATION;
	else if (delta_x < 0)
		cub->p_angle -= ROTATION;
	last_x = x;
	return (0);
}
