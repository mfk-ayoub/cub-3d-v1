/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:15:12 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/19 00:54:15 by ayel-mou         ###   ########.fr       */
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

void	get_player_angle(t_cub *cub, char **map, int row, int col)
{
	if (map[row][col] == 'N')
		cub->p_angle = 3 * (PI / 2);
	else if (map[row][col] == 'S')
		cub->p_angle = (PI / 2);
	else if (map[row][col] == 'E')
		cub->p_angle = 0;
	else if (map[row][col] == 'W')
		cub->p_angle = PI;
}

int	get_player_position(t_cub *cub, t_data *data)
{
	int	row;
	int	col;
	int	player_count;

	player_count = 0;
	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (check_player_errors(data->map, row, col, &player_count))
				return (1);
			if (data->map[row][col] == 'N' || data->map[row][col] == 'S'
				|| data->map[row][col] == 'E' || data->map[row][col] == 'W')
			{
				cub->player_x = col + 0.5;
				cub->player_y = row + 0.5;
				get_player_angle(cub, data->map, row, col);
			}
			col++;
		}
		row++;
	}
	if (player_count == 0)
		return (printf(NO_FOUND), 1);
	return (0);
}
