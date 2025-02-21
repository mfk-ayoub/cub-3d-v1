/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/21 04:46:27 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int game_loop(t_cub *cub)
{
    mlx_clear_window(cub->mlx, cub->win);
   
    ray_casting(cub, cub->data, cub->texture, cub->rays);
    path_guide(cub,cub->data);
    if (cub->img.img)
        mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
    return (0);
}

int run_the_program(t_data *data, t_cub *cub)
{
    if (get_player_position(cub, data))
        return (1);
    if (call_mlx(cub))
        return (printf(MLX_ERROR), 1);
    cub->rays = malloc(sizeof(t_rays));
    if (!cub->rays)
        return (1);
    ft_memset(cub->rays, 0, sizeof(t_rays));
    init_rays(cub->rays);
    cub->pixel_size = calculate_pixel_size(cub->data);
    if (!cub->img.img)
    {
        cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
        if (!cub->img.img)
            return (1);
        cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
                                        &cub->img.line_length, &cub->img.endian);
    }
    mlx_loop_hook(cub->mlx, game_loop, cub);
    mlx_loop(cub->mlx);
    free(cub->rays);
    if (cub->img.img)
        mlx_destroy_image(cub->mlx, cub->img.img);
    return (0);
}

int main(int ac, char **av)
{
    t_data data;
    t_cub cub;

    ft_memset(&cub, 0, sizeof(t_cub));
    ft_memset(&data, 0, sizeof(t_data));
    if (ac == 2)
    {
        if (proccess_input(&data, &cub, av[1]))
            return (1);
        if (run_the_program(&data, &cub))
            return (1);
    }
    else
        printf("Error\n");
    return (0);
}