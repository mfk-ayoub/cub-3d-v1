/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:50:48 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/16 19:42:55 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int init_data(t_data **data)
{
    *data = malloc(sizeof(t_data));
    if (!*data)
        return (1);
    (*data)->map = NULL;
    (*data)->col = 0;
    (*data)->row = 0;
    return (0);
}

int init_cub(t_cub **cub, t_data *data)
{
    *cub = malloc(sizeof(t_cub));
    if (!*cub)
        return (1);
    (*cub)->data = data;
	(*cub)->p_angle = 0;
	(*cub)->player_x = 0;
	(*cub)->player_y = 0;
    return (0);
}

int init_texture(t_texture **texture)
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