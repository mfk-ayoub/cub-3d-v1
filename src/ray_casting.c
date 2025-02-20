// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ray_casting.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/17 13:03:31 by ayel-mou          #+#    #+#             */
// /*   Updated: 2025/02/19 01:25:40 by ayel-mou         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/cub3d.h"

int get_horizontal_intersection();
int get_vertical_intersection();
void rays_data(t_cub *cub, t_rays *rays)
{
    rays->p_x = cub->player_x;
    rays->p_y = cub->player_y;


}
int ray_casting(t_cub *cub, t_data *data, t_texture *texture,t_rays *rays)
{
    int i;

    i = -1;
    rays->r_angle = cub->p_angle - (FOV / 2);
    while (++i < NUM_RAYS)
    {
        rays_data(cub,rays);
    }
    
}