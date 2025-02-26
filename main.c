/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 00:55:42 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"


void rotation(t_cub *cub)
{
    if (cub->key_right)
        cub->p_angle += ROTATION;
    else if (cub->key_left)
        cub->p_angle -= ROTATION;
    cub->p_angle = normalize_angle(cub->p_angle);
}

void movement(t_cub *cub)
{
    double new_x;
    double new_y;
    
    new_x = cub->player_x;
    new_y = cub->player_y;
    if (cub->key_w)
        move_forward(cub, &new_x, &new_y);
    else if (cub->key_s)
        move_backward(cub, &new_x, &new_y);
    else if (cub->key_a)
        move_left(cub, &new_x, &new_y);
    else if (cub->key_d)
        move_right(cub, &new_x, &new_y);
    
    if (!is_wall(cub->data, new_x, cub->player_y)) 
        cub->player_x = new_x;
    if (!is_wall(cub->data, cub->player_x, new_y)) 
        cub->player_y = new_y;
}

int game_loop(t_cub *cub)
{
    mlx_clear_window(cub->mlx, cub->win);
    ray_casting(cub, cub->data, cub->texture, cub->rays);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
    movement(cub);
    rotation(cub);
    return (0);
}


int run_the_program(t_data *data, t_cub *cub)
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
    mlx_hook(cub->win,2, 1L << 0, key_press, cub);
    mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
    mlx_loop_hook(cub->mlx, game_loop, cub);
    mlx_loop(cub->mlx);
    return (0);
}


int main(int ac, char **av)
{
    t_data data;
    t_cub *cub;

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

