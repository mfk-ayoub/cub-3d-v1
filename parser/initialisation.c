/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:50:48 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/05 22:38:04 by ayel-mou         ###   ########.fr       */
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
	return (0);
}

int	init_cub(t_cub *cub, t_data *data, t_texture *texture)
{
	cub->data = data;
	cub->p_angle = 0;
	cub->player_x = 0;
	cub->player_y = 0;
	cub->texture = texture;
	cub->key_a = false;
	cub->key_w = false;
	cub->key_s = false;
	cub->key_d = false;
	cub->key_left = false;
	cub->key_right = false;
	return (0);
}

int	init_texture(t_texture *texture)
{
	texture->no = NULL;
	texture->so = NULL;
	texture->we = NULL;
	texture->ea = NULL;
	texture->rgb = malloc(sizeof(t_rgb));
	if (!texture->rgb)
	{
		return (1);
	}
	texture->rgb->f = NULL;
	texture->rgb->c = NULL;
	texture->no_texture.img = NULL;
	texture->so_texture.img = NULL;
	texture->we_texture.img = NULL;
	texture->ea_texture.img = NULL;
	return (0);
}

void	init_rays(t_rays *rays)
{
	rays->mapx = 0;
	rays->mapy = 0;
	rays->stepx = 0;
	rays->stepy = 0;
	rays->deltax = 0.0;
	rays->deltay = 0.0;
	rays->r_angle = 0.0;
	rays->dirx = 0;
	rays->diry = 0;
	rays->side = 0;
	rays->side_dist_x = 0.0;
	rays->side_dist_y = 0.0;
	rays->ddi = 0;
	rays->anglestep = 0.0;
	rays->find_wall = 0;
	rays->distance = 0.0;
	rays->wall_x = 0.0;
	rays->w_height = 0.0;
	rays->w_top = 0.0;
	rays->w_bottom = 0.0;
}

void	init_textures(t_cub *cub)
{
	cub->texture->no_texture = load_texture(cub, cub->texture->no);
	cub->texture->so_texture = load_texture(cub, cub->texture->so);
	cub->texture->we_texture = load_texture(cub, cub->texture->we);
	cub->texture->ea_texture = load_texture(cub, cub->texture->ea);
}
