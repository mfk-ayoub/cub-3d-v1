/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathguide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:44:58 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 05:23:33 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < OFFSET)
	{
		j = 0;
		while (j < OFFSET)
		{
			put_pixel(cub, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_ray(t_cub *cub, t_minimap *mini)
{
	double	angle;

	angle = normalize_angle(mini->ray_angle);
	mini->ray_x = cub->player_x;
	mini->ray_y = cub->player_y;
	mini->delta_x = cos(angle) * MOVESTEP;
	mini->delta_y = sin(angle) * MOVESTEP;
	while (true)
	{
		if (is_wall(cub->data, mini->ray_x, mini->ray_y))
			break ;
		put_pixel(cub, (int)(mini->ray_x * OFFSET), (int)(mini->ray_y * OFFSET),
			0x98FB98);
		mini->ray_x += mini->delta_x;
		mini->ray_y += mini->delta_y;
	}
}

void	get_rays(t_cub *cub, t_minimap *mini)
{
	mini->ray_angle = cub->p_angle - (FOV / 2);
	while (mini->ray_angle <= cub->p_angle + (FOV / 2))
	{
		draw_ray(cub, mini);
		mini->ray_angle += (FOV / NUM_RAYS);
	}
}

void	path_guide(t_cub *cub)
{
	t_minimap	mini;

	mini.map_y = 0;
	while (mini.map_y < cub->data->row)
	{
		mini.map_x = 0;
		while (mini.map_x < cub->data->col)
		{
			if (cub->data->map[mini.map_y][mini.map_x] == '1')
				mini.color = 0xFFFFFF;
			else
				mini.color = 0x333333;
			draw_square(cub, mini.map_x * OFFSET, mini.map_y * OFFSET,
				mini.color);
			mini.map_x++;
		}
		mini.map_y++;
	}
	// draw_player() //todo
	get_rays(cub, &mini);
}
