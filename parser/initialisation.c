/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:50:48 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/20 04:05:38 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_data(t_data *data)
{
	data->map = NULL;
	data->col = 0;
	data->row = 0;
	data->j = 0;
	data->i = 0;
	data->c_rgb = 0;
	data->f_rgb = 0;
	return (0);
}

int	init_cub(t_cub *cub, t_data *data, t_texture *texture)
{
	cub->data = data;
	cub->p_angle = 0;
	cub->player_x = 0;
	cub->player_y = 0;
	cub->texture = texture;
	cub->tex_height = 0;
	cub->tex_width = 0;
	return (0);
}

int	init_texture(t_texture **texture)
{
	*texture = malloc(sizeof(t_texture));
	if (!*texture)
		return (1);
	(*texture)->rgb = malloc(sizeof(t_rgb));
	if (!(*texture)->rgb)
		return (free((*texture)), 1);
	(*texture)->rgb->f = NULL;
	(*texture)->rgb->c = NULL;
	(*texture)->no = NULL;
	(*texture)->so = NULL;
	(*texture)->we = NULL;
	(*texture)->ea = NULL;
	return (0);
}

void init_rays(t_rays *rays)
{
	rays->r_angle = 0;
	rays->dx = 0;
	rays->dy = 0;
	rays->r_x = 0;
	rays->r_y = 0;
	rays->side = 0;
	rays->p_x = 0;
	rays->p_y = 0; 
	rays->h_inter = 0;
	rays->v_inter = 0;
	rays->distance = 0;
}
