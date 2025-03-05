/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:36:40 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/03/05 12:48:23 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// t_maplist *get_map(int fd)
// {
//     char *line;
//     t_maplist *map;
//     int start;

//     map = NULL;
//     start = 0;
//     line = get_next_line(fd);
//     while (line)
//     {
//         if (!skip_textures(&line, fd))
//         {
//             free(line);
//             break;
//         }
//         if (start && line[0] == '\n')
//         {
//             free(line);
//             ft_mapclear(&map);
//             return (NULL);
//         }
//         if (line[0] == ' ' || line[0] == '\t' || line[0] == '1')
//         {
//             add_map_node(&map, line);
//             start = 1;
//         }
//         free(line);
//         line = get_next_line(fd);
//     }
//     return (map);
// }

// t_maplist *get_map(int fd)
// {
//     char *line;
//     char *next_line;
//     t_maplist *map;
//     int start;

//     map = NULL;
//     start = 0;
//     line = get_next_line(fd);
//     while (line)
//     {
//         next_line = get_next_line(fd);  // Read the next line in advance

//         if (!skip_textures(&line, fd))
//         {
//             free(line);
//             break;
//         }
//         if (start && line[0] == '\n')
//         {
//             free(line);
//             ft_mapclear(&map);
//             return (NULL);
//         }
//         if (line[0] == ' ' || line[0] == '\t' || line[0] == '1')
//         {
//             add_map_node(&map, line);
//             start = 1;
//         }
//         if (!next_line)// If this is the last valid line
//             start = 0;

//         free(line);
//         line = next_line;  // Move to the next line
//     }
//     return (map);
// }

t_maplist *get_map(int fd)
{
    char *line;
    char *next_line;
    t_maplist *map;
    int start;

    map = NULL;
    start = 0;
    line = get_next_line(fd);
    while (line)
    {
        if (line[0] == '\n' || line[0] == '0' || !line)
        {
            free(line);
            if (start) 
            {
                ft_mapclear(&map);
                return (NULL);
            }
            line = get_next_line(fd);
            continue;
        }
        
        if (!skip_textures(&line, fd))
        {
            free(line);
            break;
        }
        
        next_line = get_next_line(fd);
        
        if (line[0] == ' ' || line[0] == '\t' || line[0] == '1')
        {
            if (is_valid_characters(line))
            {
                free(line);
                ft_mapclear(&map);
                return (NULL);
            }
            add_map_node(&map, line);
            start = 1;
        }
        free(line);
        line = next_line;
    }
    return (map);
}
void	process_line(t_data *data, t_maplist *temp)
{
	while (temp->line[data->j])
	{
		if (temp->line[data->j] == ' ' || temp->line[data->j] == '\t'
			|| temp->line[data->j] == '\n')
                data->map[data->i][data->j] = '1';
		else
			data->map[data->i][data->j] = temp->line[data->j];
		data->j++;
	}
	while (data->j < data->col)
		data->map[data->i][data->j++] = '1';
	data->map[data->i][data->j] = '\0';
	data->i++;
}

int	init_map(t_maplist *m, t_data *data)
{
	t_maplist	*temp;

	data->col = get_biggest_line(m);
	temp = m;
	while (temp)
	{
		data->row++;
		temp = temp->next;
	}
	data->map = malloc(sizeof(char *) * (data->row + 1));
	if (!data->map)
		return (1);
	return (0);
}

int	convert_map(t_data *data, t_maplist *m)
{
	t_maplist	*temp;

	if (init_map(m, data))
		return (1);
	temp = m;
	while (data->i < data->row)
	{
		data->map[data->i] = malloc(data->col + 1);
		if (!data->map[data->i])
			return (free_array(data->map), 1);
		data->j = 0;
		process_line(data, temp);
		temp = temp->next;
	}
	data->map[data->row] = NULL;
	return (0);
}
// #include "../includes/cub3d.h"

// t_maplist	*get_map(int fd)
// {
// 	char		*line;
// 	char		*next_line;
// 	t_maplist	*map;
// 	int			start;

// 	map = NULL;
// 	start = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (!skip_textures(&line, fd))
// 		{
// 			free(line);
// 			break ;
// 		}
// 		next_line = get_next_line(fd);
// 		if (start && is_valid_characters(line))
// 		{
// 			free(line);
// 			ft_mapclear(&map);
// 			return (NULL);
// 		}
// 		if (line[0] == ' ' || line[0] == '\t' || line[0] == '1')
// 		{
// 			add_map_node(&map, line);
// 			start = 1;
// 		}
// 		else
// 			free(line);
// 		line = next_line;
// 	}
// 	return (map);
// }

// void process_line(t_data *data, t_maplist *temp)
// {
// 	while (temp->line[data->j])
// 	{
// 		if (temp->line[data->j] == ' ' || temp->line[data->j] == '\t' || temp->line[data->j] == '\n')
// 			data->map[data->i][data->j] = '1';
// 		else
// 			data->map[data->i][data->j] = temp->line[data->j];
// 		data->j++;
// 	}
// 	while (data->j < data->col)
// 		data->map[data->i][data->j++] = '1';
// 	data->map[data->i][data->j] = '\0';
// 	data->i++;
// }

// int init_map(t_maplist *m, t_data *data)
// {
// 	t_maplist	*temp;

// 	data->col = get_biggest_line(m);
// 	temp = m;
// 	while (temp)
// 	{
// 		data->row++;
// 		temp = temp->next;
// 	}
// 	data->map = malloc(sizeof(char *) * (data->row + 1));
// 	if (!data->map)
// 		return (1);
// 	return (0);
// }

// int convert_map(t_data *data, t_maplist *m)
// {
// 	t_maplist	*temp;

// 	if (init_map(m, data))
// 		return (1);
// 	temp = m;
// 	while (data->i < data->row)
// 	{
// 		data->map[data->i] = malloc(data->col + 1);
// 		if (!data->map[data->i])
// 			return (free_array(data->map), 1);
// 		data->j = 0;
// 		process_line(data, temp);
// 		temp = temp->next;
// 	}
// 	data->map[data->row] = NULL;
// 	return (0);
// }