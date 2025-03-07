/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:46:00 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/06 23:05:01 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_color(char *color)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (!(color[i] >= '0' && color[i] <= '9') && color[i] != ',')
			return (1);
		if (color[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	is_valid_rgb(char *rgb)
{
	char	**check;
	int		i;
	int		value;

	if (check_color(rgb))
		return (1);
	check = ft_split(rgb, ',');
	if (!check)
		return (1);
	i = 0;
	while (check[i])
		i++;
	if (i != 3)
		return (free_array(check), 1);
	i = -1;
	while (++i < 3)
	{
		value = ft_atoi(check[i]);
		if (value == -1)
			return (free_array(check), 1);
		if (value < 0 || value > 255)
			return (free_array(check), 1);
	}
	return (free_array(check), 0);
}

int	check_colors(t_texture *texture)
{
	if (is_valid_rgb(texture->rgb->c) || is_valid_rgb(texture->rgb->f))
		return (1);
	return (0);
}

int	parse_texture_extension(t_texture *texture)
{
	int	fd;

	fd = open(texture->ea, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open(texture->so, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open(texture->we, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	fd = open(texture->no, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	if (!check_extension(texture->no, "xpm") || !check_extension(texture->ea,
			"xpm") || !check_extension(texture->we, "xpm")
		|| !check_extension(texture->so, "xpm"))
		return (1);
	return (0);
}
