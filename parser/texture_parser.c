/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:45:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/27 02:34:01 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_texture_path(t_texture *texture, char *line, char *trimmed)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (texture->no)
			return (1);
		texture->no = ft_strdup(trimmed);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (texture->so)
			return (1);
		texture->so = ft_strdup(trimmed);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (texture->we)
			return (1);
		texture->we = ft_strdup(trimmed);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (texture->ea)
			return (1);
		texture->ea = ft_strdup(trimmed);
	}
	return (0);
}

int	texture_path(t_texture *texture, char *line, char *trimmed)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (texture->rgb->f)
			return (1);
		texture->rgb->f = ft_strdup(trimmed);
		return (free(trimmed), 0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (texture->rgb->c)
			return (1);
		texture->rgb->c = ft_strdup(trimmed);
		return (free(trimmed), 0);
	}
	else if (set_texture_path(texture, line, trimmed) == 0)
		return (free(trimmed), 0);
	return (1);
}

int	parse_texture_line(t_texture *texture, char *line)
{
	char	*trimmed;
	int		ret;

	if (line[0] == 'F')
		trimmed = ft_strtrim(&line[2], "\n");
	else if (line[0] == 'C')
		trimmed = ft_strtrim(&line[2], "\n");
	else
		trimmed = ft_strtrim(&line[3], "\n");
	if (!trimmed)
	{
		free(line);
		return (1);
	}
	ret = texture_path(texture, line, trimmed);
	if (ret == 0)
	{
		free(line);
		return (0);
	}
	free(line);
	if (ret == 1)
		free(trimmed);
	return (1);
}

int	read_texture_lines(t_texture *texture, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL || ft_strlen(line) == 0 || ft_strspn(line, " \t\n") == ft_strlen(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (line[0] == '1' || line[0] == '0')
		{
			free(line);
			break ;
		}
		if (parse_texture_line(texture, line))
			return (1);

		line = get_next_line(fd);
	}
	return (0);
}

int	valid_texture(t_texture *texture, int fd)
{
	if (read_texture_lines(texture, fd))
	{
		printf(TEXTURE);
		return (1);
	}
	else if (!texture->no || !texture->so || !texture->we || !texture->ea
		|| !texture->rgb->f || !texture->rgb->c)
		return (printf(TEXTURE), 1);
	else if (parse_texture_extension(texture))
		return (printf(T_EXTENTASION), 1);
	else if (check_colors(texture))
		return (printf(COLORS_ERROR), 1);
	else
		return (0);
}