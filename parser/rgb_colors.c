/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:13:37 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/22 02:03:42 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_to_int(int red, int green, int blue)
{
	int	shifted_red;
	int	shifted_green;
	int	shifted_blue;
	int	result;

	shifted_red = red << 16;
	shifted_green = green << 8;
	shifted_blue = blue;
	result = shifted_red | shifted_green | shifted_blue;
	return (result);
}


int get_colors(char *rgb)
{
    char **colors;
    int red, green, blue;
    int result;

    colors = ft_split(rgb, ',');
    if (!colors || !colors[0] || !colors[1] || !colors[2])
    {
        free_array(colors); 
        return (-1);
    }
    red = ft_atoi(colors[0]);
    green = ft_atoi(colors[1]);
    blue = ft_atoi(colors[2]);

    free_array(colors);
    result = rgb_to_int(red, green, blue);
    return (result);
}
