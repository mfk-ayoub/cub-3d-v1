/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:15:12 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/17 13:19:34 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_player_errors(char **map)
{
	int	row;
	int col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			col++;
		}
		row++;
	}
	
	return (0);
}

int get_player_angle(t_cub *cub, t_data *data)
{
		
}