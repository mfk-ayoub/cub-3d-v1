/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:21:09 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/19 01:36:45 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define BUFFER_SIZE 1
# define RED "\033[31m"
# define DEFAULT "\033[0m"
# define PI 3.141592653589793
# define FOV 60 * (PI / 180.0)
# define TILE_SIZE 10
# define SCALE 0.5
# define OFFSET 4
# define MOVESTEP 0.5
# define RADIUS 4
# define NUM_RAYS 800

# define EXTENTASION RED "error: " DEFAULT "Invalid extension\n"
# define TEXTURE RED "error: " DEFAULT "Textures not found\n"
# define T_EXTENTASION RED "error: " DEFAULT "Invalid texture extension\n"
# define COLORS_ERROR RED "error: " DEFAULT "Invalid colours\n"
# define INVALID_MAP RED "error: " DEFAULT "Invalid Map\n"
# define FILE_ERROR RED "error: " DEFAULT "Error in open file\n"
# define MLX_ERROR RED "error: " DEFAULT "in mlx\n"
# define NO_FOUND RED "error: " DEFAULT "No player found on the map.\n"
# define FOUND_DUP RED "error: " DEFAULT "Multiple player positions found.\n"
#endif