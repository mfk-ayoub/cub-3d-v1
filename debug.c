#include "includes/cub3d.h"


void print_map(t_data *data)
{
    for (int i = 0; data->map[i]; i++)
        printf("%s\n", data->map[i]);
}

void print_map_list(t_maplist *tmp)
{
	while (tmp)
	{
		printf("%s",tmp->line);
		tmp  =  tmp->next;
	}
}
void debug(t_cub *cub,t_data *data , t_texture *texture)
{
	(void)cub;
	print_map(data);
	printf("North Texture: %s\n", texture->no);
	printf("South Texture: %s\n", texture->so);
	printf("West Texture: %s\n", texture->we);
	printf("East Texture: %s\n", texture->ea);
	printf("c : %s\n", texture->rgb->c);
	printf("f : %s\n", texture->rgb->f);
}