/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:55:10 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 01:03:21 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_mapclear(t_maplist **map)
{
	t_maplist	*tmp;

	if (!map || !*map)
		return ;
	while (*map)
	{
		tmp = *map;
		*map = (*map)->next;
		free(tmp->line);
		free(tmp);
	}
	*map = NULL;
}

void	destroy_data(t_data *data, t_texture *texture)
{
	if (texture)
	{
		if (texture->rgb)
		{
			free(texture->rgb->f);
			free(texture->rgb->c);
			free(texture->rgb);
		}
		free(texture->no);
		free(texture->so);
		free(texture->we);
		free(texture->ea);
		free(texture);
	}
	if (data)
	{
		free_array(data->map);
		data->map = NULL;
	}
}

void	destroy_all(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->mlx && cub->img.img)
		mlx_destroy_image(cub->mlx, cub->img.img);
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	destroy_data(cub->data, cub->texture);
	free(cub->rays);
	free(cub);
	exit(0);
}
