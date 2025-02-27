/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:42:17 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/27 13:08:44 by ayel-mou         ###   ########.fr       */
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
# define PI 3.141592653589793
# define FOV 1.0471975512
# define OFFSET 4
# define ROTATION 0.01
# define MOVESTEP 0.02
# define NUM_RAYS 1200
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RIGHT 65363
# define LEFT 65361
# define FRAMES 4
# define EXTENTASION "\033[31m error: \033[0m Invalid extension\n"
# define TEXTURE "\033[31m  error:  \033[0m  Textures not found\n"
# define T_EXTENTASION "\033[31m  error:  \033[0m  Invalid texture extension\n"
# define COLORS_ERROR "\033[31m  error:  \033[0m  Invalid colours\n"
# define INVALID_MAP "\033[31m  error:  \033[0m  Invalid Map\n"
# define FILE_ERROR "\033[31m  error:  \033[0m  Error in open file\n"
# define MLX_ERROR "\033[31m  error:  \033[0m  in mlx\n"
# define NO_FOUND "\033[31m  error:  \033[0m  No player found on the map.\n"
# define FOUND_DUP "\033[31m  error:  \033[0m  Multiple player positions\n"
# define TEXTURE_FAILD "\033[31m  error:  \033[0m  error in load texture\n"

#endif
