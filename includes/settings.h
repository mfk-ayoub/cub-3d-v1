/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:21:09 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/17 13:02:52 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 800
# define BUFFER_SIZE 1

# define RED "\033[31m"
# define DEFAULT "\033[0m"

# define NUM_OF_RAYS 1200
# define PI 3.141592653589793
# define FOV 60 * (PI / 180.0)

# define EXTENTASION RED "error: " DEFAULT "Invalid extension\n"
# define TEXTURE RED "error: " DEFAULT "Textures not found\n"
# define T_EXTENTASION RED "error: " DEFAULT "Invalid texture extension\n"
# define COLORS_ERROR RED "error: " DEFAULT "Invalid colours\n"
# define INVALID_MAP RED "error: " DEFAULT "Invalid Map\n"
# define FILE_ERROR RED "error: " DEFAULT "Error in open file\n"
# define MLX_ERROR  RED "error: " DEFAULT  "in mlx\n"
#endif