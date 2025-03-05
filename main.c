/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/05 14:10:39 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"



void	texture_pixel(t_cub *cub, t_mlx texture, int map_x, int map_y)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < texture.height)
	{
		x = 0;
		while (x < texture.width)
		{
			color = get_pixel_color(texture, x, y);
			if (color != -16777216)
				put_pixel(cub, map_x + x, map_y + y, color);
			x++;
		}
		y++;
	}
}

int	game_loop(t_cub *cub)
{
	
	mlx_clear_window(cub->mlx, cub->win);
	ray_casting(cub, cub->data, cub->texture, cub->rays);
	texture_pixel(cub,cub->texture->shot,100, 100);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	movement(cub);
	rotation(cub);
	return (0);
}

int mouse_move(int x, int y, t_cub *cub)
{
    (void)y;
	int delta_x;
	static int last_x; 

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


int	run_the_program(t_data *data, t_cub *cub)
{
	if (get_player_position(cub, data))
		return (1);
	if (call_mlx(cub))
		return (printf(MLX_ERROR), 1);
	cub->rays = malloc(sizeof(t_rays) * NUM_RAYS);
	if (!cub->rays)
		return (1);
	ft_memset(cub->rays, 0, sizeof(t_rays) * NUM_RAYS);
	init_rays(cub->rays);
	init_textures(cub);
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->win, 6, 1L << 6, mouse_move, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
	return (0);
}
void kill_leaks(t_data *data, t_cub *cub)
{
    (void)data;
    
	free(cub->texture->rgb);
	cub->texture->rgb = NULL;
	free(cub->texture);
	cub->texture = NULL;
	free(cub);
}


int	main(int ac, char **av)
{
	t_data	data;
	t_cub	*cub;
	t_texture	*texture;
	
	cub = malloc(sizeof(t_cub));
	texture = malloc(sizeof(t_texture));
    if (!texture)
        return (1);
    ft_memset(cub, 0, sizeof(t_cub));
	ft_memset(&data, 0, sizeof(t_data));
	if (ac == 2)
	{
		if (proccess_input(&data, cub, av[1],texture))
		{
			kill_leaks(&data,cub);
			return (1);
		}
		if (run_the_program(&data, cub))
		{
			destroy_all(cub);
			return (1);
		}
	}
	else
		printf("Error\n");
	return (0);
}
