/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_clicks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:48:13 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 00:48:51 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_release(int key, t_cub *cub)
{
	if (key == A)
		cub->key_a = false;
	else if (key == D)
		cub->key_d = false;
	else if (key == S)
		cub->key_s = false;
	else if (key == W)
		cub->key_w = false;
	else if (key == RIGHT)
		cub->key_right = false;
	else if (key == LEFT)
		cub->key_left = false;
	return (0);
}

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
	{
		destroy_all(cub);
		exit(0);
	}
	else if (key == A)
		cub->key_a = true;
	else if (key == D)
		cub->key_d = true;
	else if (key == S)
		cub->key_s = true;
	else if (key == W)
		cub->key_w = true;
	else if (key == RIGHT)
		cub->key_right = true;
	else if (key == LEFT)
		cub->key_left = true;
	return (0);
}
