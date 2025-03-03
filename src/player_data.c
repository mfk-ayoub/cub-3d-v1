/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:15:12 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/03 14:17:10 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_player_errors(char **map, int row, int col, int *player_count)
{
	if (map[row][col] == 'N' || map[row][col] == 'S' || map[row][col] == 'E'
		|| map[row][col] == 'W')
	{
		(*player_count)++;
		if (*player_count > 1)
		{
			printf(FOUND_DUP);
			return (1);
		}
	}
	return (0);
}

void	set_player_data(t_cub *cub, t_data *data, int row, int col)
{
	cub->player_x = col + 0.5;
	cub->player_y = row + 0.5;
	if (data->map[row][col] == 'N')
		cub->p_angle =  PI / 2;
	else if (data->map[row][col] == 'S')
		cub->p_angle = 3 * PI / 2;
	else if (data->map[row][col] == 'E')
		cub->p_angle = 0;
	else if (data->map[row][col] == 'W')
		cub->p_angle = PI;
	data->map[row][col] = '0';
}

int	get_player_position(t_cub *cub, t_data *data)
{
	int	row;
	int	col;
	int	player_count;

	player_count = 0;
	row = 0;
	while (row < data->row)
	{
		col = 0;
		while (col < data->col)
		{
			if (check_player_errors(data->map, row, col, &player_count))
				return (1);
			if (data->map[row][col] == 'N' || data->map[row][col] == 'S'
				|| data->map[row][col] == 'E' || data->map[row][col] == 'W')
				set_player_data(cub, data, row, col);
			col++;
		}
		row++;
	}
	if (player_count == 0)
		return (printf(NO_FOUND), 1);
	return (0);
}
