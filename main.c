/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/18 02:08:42 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"




int	game_loop(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	// ray_casting(cub, cub->data);
	// render(cub);
	cub->pixel_size = calculate_pixel_size(cub->data);
	draw_circle(cub);
	path_guide(cub, cub->data);
	// draw_mini_map(cub,cub->map);
	// draw_player(cub, cub->player_x, cub->player_y, 0xFFA500);
	// draw_rays(cub,cub->rays);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (0);
}

int run_the_program(t_data *data,t_cub *cub)
{
	if (get_player_position(cub,data))
		return (1);
    if (call_mlx(cub))
        return (printf(MLX_ERROR), 1);
    // mlx_hook(cub->win, 2, 1L << 0, clean, cub);
    mlx_loop_hook(cub->mlx, game_loop, cub);
    mlx_loop(cub->mlx);
    return (0);
}

int	main(int ac, char **av)
{
	t_data data;
	t_cub  cub;
	

	if (ac == 2)
	{
		if (proccess_input(&data,&cub,av[1]))
			return (1);
		// debug(&cub,&data,cub.texture);
		if (run_the_program(&data,&cub))
			return (1);
	}
	else
		printf("Error\n");
	return (0);
}