/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maplist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:06:03 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/09 23:17:44 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_maplist	*create_map(char *line)
{
	t_maplist	*node;

	node = (t_maplist *)malloc(sizeof(t_maplist));
	if (!node)
		return (NULL);
	node->line = ft_strdup(line);
	node->next = NULL;
	return (node);
}

void	add_map_node(t_maplist **head, char *line)
{
	t_maplist	*node;
	t_maplist	*temp;

	node = create_map(line);
	if (!node)
		return ;
	if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

t_maplist	*get_map(int fd)
{
	char		*line;
	t_maplist	*map;
	int			start;

	map = NULL;
	start = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (process_map(&line, fd, &map, &start))
			return (free(line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

int	is_valid_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' '
			&& line[i] != '\t' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	skip_textures(char **line, int fd)
{
	char	*new_line;

	while (*line)
	{
		new_line = remove_spaces(*line);
		free(*line);
		*line = new_line;
		if (!ft_strncmp(*line, "NO", 2) || !ft_strncmp(*line, "SO", 2)
			|| !ft_strncmp(*line, "WE", 2) || !ft_strncmp(*line, "EA", 2)
			|| (*line)[0] == 'F' || (*line)[0] == 'C')
		{
			free(*line);
			*line = get_next_line(fd);
		}
		else
			break ;
	}
	return (*line != NULL);
}
