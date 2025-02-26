/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:16:39 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 05:17:07 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotation(t_cub *cub)
{
	if (cub->key_right && !cub->key_left)
		cub->p_angle += ROTATION;
	else if (cub->key_left && !cub->key_right)
		cub->p_angle -= ROTATION;
	cub->p_angle = normalize_angle(cub->p_angle);
}

void	movement(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player_x;
	new_y = cub->player_y;
	if (cub->key_w)
		move_forward(cub, &new_x, &new_y);
	else if (cub->key_s)
		move_backward(cub, &new_x, &new_y);
	else if (cub->key_a)
		move_left(cub, &new_x, &new_y);
	else if (cub->key_d)
		move_right(cub, &new_x, &new_y);
	if (!is_wall(cub->data, new_x, cub->player_y))
		cub->player_x = new_x;
	if (!is_wall(cub->data, cub->player_x, new_y))
		cub->player_y = new_y;
}
