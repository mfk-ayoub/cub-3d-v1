/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:28:12 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/25 23:57:38 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_cub *cub, double *new_x, double *new_y)
{
	*new_x = cub->player_x + (cos(cub->p_angle) * MOVESTEP);
	*new_y = cub->player_y + (sin(cub->p_angle) * MOVESTEP);
}

void	move_backward(t_cub *cub, double *new_x, double *new_y)
{
	*new_x = cub->player_x - (cos(cub->p_angle) * MOVESTEP);
	*new_y = cub->player_y - (sin(cub->p_angle) * MOVESTEP);
}

void	move_left(t_cub *cub, double *new_x, double *new_y)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = cos(cub->p_angle);
	tmp_y = sin(cub->p_angle);
	*new_x = cub->player_x + (tmp_y * MOVESTEP);
	*new_y = cub->player_y - (tmp_x * MOVESTEP);
}

void	move_right(t_cub *cub, double *new_x, double *new_y)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = cos(cub->p_angle);
	tmp_y = sin(cub->p_angle);
	*new_x = cub->player_x - (tmp_y * MOVESTEP);
	*new_y = cub->player_y + (tmp_x * MOVESTEP);
}
