// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
// /*   Updated: 2025/02/19 01:03:34 by ayel-mou         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "includes/cub3d.h"




int game_loop(t_cub *cub)
{
    mlx_clear_window(cub->mlx, cub->win);
    ray_casting(cub, cub->data, cub->texture, cub->rays);
    
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
    // mlx_hook(cub->win, 2, 1L << 0, key_hook, cub); 
    mlx_loop_hook(cub->mlx, game_loop, cub);
    mlx_loop(cub->mlx);
    free(cub->rays);
    return (0);
}

int main(int ac, char **av)
{
    t_data data;
    t_cub cub;

    ft_memset(&cub,0,sizeof(t_cub));
    ft_memset(&data,0,sizeof(t_data));
    if (ac == 2)
    {
        if (proccess_input(&data, &cub, av[1]))
            return (1);
        // debug(&cub, &data, cub.texture);
        if (run_the_program(&data, &cub))
            return (1);
    }
    else
        printf("Error\n");
    return (0);
}