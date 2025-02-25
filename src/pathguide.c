// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pathguide.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/21 03:47:27 by ayel-mou          #+#    #+#             */
// /*   Updated: 2025/02/24 23:15:08 by ayel-mou         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cub3d.h"

// #define MINIMAP_SCALE 0.25 
// void	draw_circle(t_cub *cub, int center_x, int center_y, int radius,
// 		int color)
// {
// 	int	pixel_x;
// 	int	pixel_y;

// 	for (int y = -radius; y <= radius; y++)
// 	{
// 		for (int x = -radius; x <= radius; x++)
// 		{
// 			if (x * x + y * y <= radius * radius)
// 			{
// 				pixel_x = center_x + x;
// 				pixel_y = center_y + y;
// 				if (pixel_x >= 0 && pixel_x < (int)(WIDTH * MINIMAP_SCALE)
// 					&& pixel_y >= 0 && pixel_y < (int)(HEIGHT * MINIMAP_SCALE))
// 					put_pixel(cub, pixel_x, pixel_y, color);
// 			}
// 		}
// 	}
// }

// int	calculate_pixel_size(t_data *data)
// {
// 	int	minimap_w;
// 	int	minimap_h;
// 	int	pixel_size_w;
// 	int	pixel_size_h;

// 	if (!data || data->row <= 0 || data->col <= 0)
// 		return (0);
// 	minimap_w = (int)(WIDTH * MINIMAP_SCALE);  // 200 pixels
// 	minimap_h = (int)(HEIGHT * MINIMAP_SCALE); // 150 pixels
// 	pixel_size_w = minimap_w / data->col;
// 	pixel_size_h = minimap_h / data->row;
// 	return (fmax(1, fmin(pixel_size_w, pixel_size_h)));
// 	// Ensure at least 1 pixel per tile for clarity
// }

// void	put_pixel_map(t_cub *cub, int map_x, int map_y, int color)
// {
// 	int	i;
// 	int	j;
// 	int	new_x;
// 	int	new_y;

// 	for (i = 0; i < cub->pixel_size; i++)
// 	{
// 		for (j = 0; j < cub->pixel_size; j++)
// 		{
// 			new_x = map_x + j;
// 			new_y = map_y + i;
// 			if (new_x >= 0 && new_x < (int)(WIDTH * MINIMAP_SCALE) && new_y >= 0
// 				&& new_y < (int)(HEIGHT * MINIMAP_SCALE))
// 				put_pixel(cub, new_x, new_y, color);
// 		}
// 	}
// }

// void	path_guide(t_cub *cub, t_data *data)
// {
// 	int y;
// 	int x;

// 	if (!data || !data->map || !cub)
// 		return ;

// 	cub->pixel_size = calculate_pixel_size(data);
// 	if (cub->pixel_size <= 0)
// 		return ;

// 	// Position minimap in the top-left corner (200x150 pixels)

// 	int player_x = (int)(cub->player_x / TILE_SIZE);
// 	int player_y = (int)(cub->player_y / TILE_SIZE);
// 	if (player_x >= 0 && player_x < data->col && player_y >= 0
// 		&& player_y < data->row)
// 	{
// 		int center_x = player_x * cub->pixel_size + (cub->pixel_size / 2);
// 		int center_y = player_y * cub->pixel_size + (cub->pixel_size / 2);
// 		// draw_circle(cub, center_x, center_y, 1, 0xFFFFFF);
// 		// Small white circle for player (radius 1 for 3x3)
// 	}

// 	// Step 2: Draw the map (walls and empty spaces) after the player
// 	for (y = 0; y < data->row; y++)
// 	{
// 		for (x = 0; x < data->col; x++)
// 		{
// 			if (data->map[y] && x < (int)ft_strlen(data->map[y]))
// 			{
// 				if (data->map[y][x] == '1')
// 					put_pixel_map(cub, x * cub->pixel_size, y * cub->pixel_size,
// 									0x7F8C8D); // Gray for walls
// 				else if (data->map[y][x] == '0' || data->map[y][x] == 'P'
// 					|| data->map[y][x] == 'N' || data->map[y][x] == 'S'
// 					|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
// 					put_pixel_map(cub, x * cub->pixel_size, y * cub->pixel_size,
// 									0x4D5656); // Dark gray for empty spaces
// 			}
// 		}
// 	}
// }