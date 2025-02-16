/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapassistants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:09:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/16 20:25:12 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	get_biggest_line(t_maplist *head)
{
	int	big_line;
	int	current_len;

	big_line = 0;
	while (head)
	{
		current_len = ft_strlen(head->line);
		if (current_len > big_line)
			big_line = current_len;
		head = head->next;
	}
	return (big_line);
}

int	is_not_closed(t_maplist *prev, t_maplist *current, t_maplist *next)
{
	int	i;

	i = 0;
	while (current->line[i])
	{
		if (current->line[i] == '0' || current->line[i] == 'N'
			|| current->line[i] == 'S' || current->line[i] == 'W'
			|| current->line[i] == 'E')
		{
			if (i > 0 && check_space(current->line[i - 1]))
				return (1);
			if (current->line[i + 1] && check_space(current->line[i + 1]))
				return (1);
			if (prev && i < (int)ft_strlen(prev->line)
				&& check_space(prev->line[i]))
				return (1);
			if (next && i < (int)ft_strlen(next->line)
				&& check_space(next->line[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	validate_map(t_maplist *map)
{
	t_maplist	*prev;
	t_maplist	*next;
	t_maplist	*current;

	prev = NULL;
	current = map;
	while (current)
	{
		next = current->next;
		if (is_not_closed(prev, current, next))
			return (1);
		prev = current;
		current = next;
	}
	return (0);
}
