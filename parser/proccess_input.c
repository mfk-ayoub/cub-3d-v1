/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:46:01 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/02/16 19:54:53 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_extension(char *exten, char *s)
{
	int		len;
	char	*copy;
	int		i;
	bool	result;

	i = 0;
	len = ft_strlen(exten);
	copy = malloc(sizeof(char) * (len + 1));
	while (exten[len] != '.' && len > 0)
		len--;
	if (exten[len] == '.')
	{
		len++;
		while (exten[len] != '\0')
		{
			copy[i++] = exten[len++];
		}
	}
	copy[i] = '\0';
	result = ft_strncmp(s, copy, ft_strlen(s)) == 0;
	free(copy);
	return (result);
}

int start_parser(t_texture *texture, char *path,int fd)
{
	// (void)data;
	if (!check_extension(path, "cub"))
	{
		printf(EXTENTASION);
		return (1);
	}
	if (valid_texture(texture, fd))
	{
		
	}
	return (0);
}

int proccess_input(t_data *data, t_cub *cub, char *path)
{
   	t_texture *texture;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error in open file\n");
		exit(EXIT_FAILURE);
	}
    if (init_data(&data))
		exit(EXIT_FAILURE);
	if (init_cub(&cub, data))
	{
		free(data);
		exit(EXIT_FAILURE);	
	}
	if(init_texture(&texture))
    {
		free(cub),free(data);
		exit(EXIT_FAILURE);	
	}
	if (start_parser(texture,path,fd))
		return (1);
    return (0);
}

