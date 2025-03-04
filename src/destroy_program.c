/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:55:10 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/04 15:09:08 by ayel-mou         ###   ########.fr       */
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
	
	free(texture->rgb->f);
	free(texture->rgb->c);
	free(texture->rgb);
	free(texture->no);
	free(texture->so);
	free(texture->we);
	free(texture->ea);
	free(texture);
	free_array(data->map);
	data->map = NULL;

}

void destroy_all(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->texture->no_texture.img);
	mlx_destroy_image(cub->mlx, cub->texture->so_texture.img);
	mlx_destroy_image(cub->mlx, cub->texture->we_texture.img);
	mlx_destroy_image(cub->mlx, cub->texture->ea_texture.img);
	destroy_data(cub->data,cub->texture);
    mlx_clear_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
    free(cub->mlx);
    free(cub->rays);
    free(cub);
    exit(0);
}