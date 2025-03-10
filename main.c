/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/10 22:47:00 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	game_loop(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	ray_casting(cub, cub->data, cub->texture, cub->rays);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	movement(cub);
	rotation(cub);
	return (0);
}

int	ft_exit(t_cub *cub)
{
	destroy_all(cub);
	exit(0);
	return (0);
}

int	run_the_program(t_data *data, t_cub *cub)
{
	if (get_player_position(cub, data))
	{
		destroy_data(data, cub->texture);
		free(cub);
		exit(1);
	}
	if (call_mlx(cub))
		return (printf(MLX_ERROR), 1);
	cub->rays = malloc(sizeof(t_rays));
	if (!cub->rays)
		return (1);
	ft_memset(cub->rays, 0, sizeof(t_rays));
	init_rays(cub->rays);
	init_textures(cub);
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->win, 6, 1L << 6, mouse_move, cub);
	mlx_hook(cub->win, 17, 0, ft_exit, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_cub		*cub;
	t_texture	*texture;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (1);
	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (free(cub), 1);
	ft_memset(cub, 0, sizeof(t_cub));
	ft_memset(&data, 0, sizeof(t_data));
	if (ac == 2)
	{
		if (proccess_input(&data, cub, av[1], texture))
			return (kill_leaks(cub), 1);
		if (run_the_program(&data, cub))
			return (destroy_all(cub), 1);
	}
	else
		return (printf("Error\n"), free(cub), free(texture), 1);
	return (0);
}
