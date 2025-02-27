/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 05:40:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/26 05:40:49 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int index)
{
	if ('0' <= index && index <= '9')
		return (1);
	return (0);
}

static bool	is_space(char c)
{
	char	*str;

	str = "\t\n\v\f\r ";
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

int	ft_atoi(char *str)
{
	int	ans;
	int	result;

	if (!str)
		return (-1);
	ans = 0;
	result = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+' || *str == '-')
		return (-1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		ans = (ans * 10) + (*str - '0');
		str++;
	}
	return (result * ans);
}
