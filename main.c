/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 05:17:02 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	game_loop(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	ray_casting(cub, cub->data, cub->texture, cub->rays);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	path_guide(cub);
	movement(cub);
	rotation(cub);
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
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	ft_memset(&data, 0, sizeof(t_data));
	if (ac == 2)
	{
		if (proccess_input(&data, cub, av[1]))
			return (1);
		if (run_the_program(&data, cub))
			return (1);
	}
	else
		printf("Error\n");
	return (0);
}
