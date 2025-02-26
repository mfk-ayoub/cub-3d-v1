/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:07:00 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 04:42:20 by ayel-mou         ###   ########.fr       */
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
	int					mapx;
	int					mapy;
	int					stepx;
	int					stepy;
	double				deltax;
	double				deltay;
	double				r_angle;
	double				dirx;
	double				diry;
	int					side;
	double				side_dist_x;
	double				side_dist_y;
	int					ddi;
	double				anglestep;
	int					find_wall;
	double				distance;
	double				wall_x;
	double				w_height;
	double				w_top;
	double				w_bottom;
}						t_rays;

typedef struct s_mlx
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
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
	t_mlx				no_texture;
	t_mlx				so_texture;
	t_mlx				we_texture;
	t_mlx				ea_texture;
	int					c_color;
	int					f_color;
}						t_texture;

typedef struct s_data
{
	char				**map;
	int					row;
	int					col;
	int					j;
	int					i;
}						t_data;

typedef struct s_wall
{
	int					tex_x;
	int					tex_y;
	double				step;
	double				tex_pos;
	int					color;
}						t_wall;

typedef struct s_minimap
{
	double				ray_x;
	double				ray_y;
	double				delta_x;
	double				delta_y;
	double				ray_angle;
	int					map_x;
	int					map_y;
	int					color;
}						t_minimap;

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
	bool				key_w;
	bool				key_s;
	bool				key_a;
	bool				key_d;
	bool				key_right;
	bool				key_left;
	t_data				*data;
	t_texture			*texture;
	t_rays				*rays;
}						t_cub;

#endif