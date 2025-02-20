/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:07:00 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/20 03:42:01 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_maplist
{
	char				*line;
	struct s_maplist	*next;
}						t_maplist;

typedef struct s_rays
{
	float					r_x;
	float					r_y;
	float				p_x;
	float				p_y;
	double				r_angle;
	double 				dx;
	double				dy;
	int					side;
}						t_rays;

typedef struct s_mlx
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_mlx;

typedef struct s_rgb
{
	char				*f;
	char				*c;
}						t_rgb;

typedef struct s_texture
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	t_rgb				*rgb;
}						t_texture;

typedef struct s_data
{
	char				**map;
	int					row;
	int					col;
	int					j;
	int					i;
	int					f_rgb;
	int 				c_rgb;
}						t_data;

typedef struct s_cub
{
	void				*mlx;
	void				*win;
	t_mlx				img;
	int					mini_width;
	int					mini_height;
	float				player_x;
	float				player_y;
	float				p_angle;
	int					pixel_size;
	t_data				*data;
	t_texture			*texture;
	t_rays				*rays;
	int tex_width;
	int tex_height;
}						t_cub;

#endif