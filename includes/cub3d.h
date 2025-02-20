/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:43:15 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/20 05:58:11 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "settings.h"
# include "structs.h"

// parser
int			proccess_input(t_data *data, t_cub *cub, char *path);
int			init_texture(t_texture **texture);
int			init_data(t_data *data);
int			init_cub(t_cub *cub, t_data *data, t_texture *texture);
int			ft_atoi(char *str);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memcpy(void *to, const void *from, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strtrim(char const *s1, char const *set);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strspn(const char *s, const char *accept);
int			check_space(char c);
int			newline_checker(t_list *list);
int			llist(t_list *list);
void		copy_the_list(t_list *list, char *the_line);
void		dealloc(t_list **list, t_list *clean_node, char *buf);
char		*ft_strchr(const char *s, int c);
int			valid_texture(t_texture *texture, int fd);
int			is_valid_rgb(char *rgb);
int			check_colors(t_texture *texture);
int			parse_texture_extension(t_texture *texture);
int			read_texture_lines(t_texture *texture, int fd);
int			parse_texture_line(t_texture *texture, char *line);
int			texture_path(t_texture *texture, char *line, char *trimmed);
int			set_texture_path(t_texture *texture, char *line, char *trimmed);
void		free_array(char **arr);
int			check_extension(char *exten, char *s);
t_maplist	*create_map(char *line);
void		add_map_node(t_maplist **head, char *line);
int			skip_textures(char **line, int fd);
int			is_valid_characters(char *line);
int			init_map(t_maplist *m, t_data *data);
int			convert_map(t_data *data, t_maplist *m);
int			is_not_closed(t_maplist *prev, t_maplist *current, t_maplist *next);
int			validate_map(t_maplist *map);
int			convert_map(t_data *data, t_maplist *m);
void		process_line(t_data *data, t_maplist *temp);
t_maplist	*get_map(int fd);
int			get_biggest_line(t_maplist *head);
void		ft_mapclear(t_maplist **map);
void		*ft_memset(void *ptr, int x, size_t n);
// render

double		calculate_distance(double x1, double x2, double y1, double y2);
int			call_mlx(t_cub *cub);
int			get_player_position(t_cub *cub, t_data *data);
void		put_pixel_to_image(t_mlx img, int x, int y, int color);
void		path_guide(t_cub *cub, t_data *data);
void		put_pixel(t_cub *cub, double map_x, double map_y, int color);
int			calculate_pixel_size(t_data *data);
void		draw_player(t_cub *cub, int px, int py, int color);
int			ray_casting(t_cub *cub, t_data *data, t_texture *texture,
				t_rays *rays);
void		init_rays(t_rays *rays);
float	normalize_angle(float angle);
int check_if_wall(t_data *data, float x, float y);
// debug

void		debug(t_cub *cub, t_data *data, t_texture *texture);

#endif