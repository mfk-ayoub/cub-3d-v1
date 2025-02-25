/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:05:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/25 04:00:13 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"


int is_wall(t_data *data, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;

    printf("x=%f, y=%f -> map_x=%d, map_y=%d\n", x, y, map_x, map_y);
    printf("data->row=%d, data->col=%d\n", data->col, data->row);

    if (map_x < 0 || map_y < 0 || map_x >= data->col || map_y >= data->row)
        return (1);

    printf(" data->map[%d][%d]\n", map_y, map_x);
    if (data->map[map_y][map_x] == '1')
        return (1);

    return (0);
}

void movement(t_cub *cub)
{
    double new_x;
    double new_y;
    
    new_y =  cub->player_y;
    new_x = cub->player_x;
    if (cub->key_w)
    {
        new_x = cub->player_x + (cub->rays->dirx * MOVESTEP);
        new_y = cub->player_y + (cub->rays->diry * MOVESTEP);
    }
    if (cub->key_s)
    {
        new_x = cub->player_x - (cub->rays->dirx * MOVESTEP);
        new_y = cub->player_y - (cub->rays->diry * MOVESTEP);
    }
    if (cub->key_a)
    {
        new_x = cub->player_x - (cub->rays->dirx * MOVESTEP);
        new_y = cub->player_y + (cub->rays->diry * MOVESTEP);
    }
    if (cub->key_d)
    {
        new_x = cub->player_x + (cub->rays->dirx * MOVESTEP);
        new_y = cub->player_y - (cub->rays->diry * MOVESTEP);
    }
    if (!is_wall(cub->data, new_x, cub->player_y)) 
        cub->player_x = new_x;
    if (!is_wall(cub->data, cub->player_x, new_y)) 
        cub->player_y = new_y;
}



int key_release(int key, t_cub *cub)
{
    if (key == A)
        cub->key_a = false;
    else if (key == D)
        cub->key_d = false;
    else if (key == S)
        cub->key_s = false;
    else if (key == W)
        cub->key_w = false;
    return (0);   
}

int key_press(int key, t_cub *cub)
{
    if (key == ESC)
    {
        destroy_all(cub);
        exit(0);
    }
    else if (key == A)
        cub->key_a = true;
    else if (key == D)
        cub->key_d = true;
    else if (key == S)
        cub->key_s = true;
    else if (key == W)
        cub->key_w = true;
    return (0);   
}


int game_loop(t_cub *cub)
{
    mlx_clear_window(cub->mlx, cub->win);
    ray_casting(cub, cub->data, cub->texture, cub->rays);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
    movement(cub);
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
    // cub->pixel_size = calculate_pixel_size(cub->data);
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
    // ft_memset(&cub, 0, sizeof(t_cub));
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

