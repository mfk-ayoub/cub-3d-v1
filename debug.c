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

void rays_debug(t_rays *rays)
{
	printf(" ray distance %f\n",rays->distance);
	printf(" ray ddi %d\n",rays->ddi);
	printf("rays stepx %d and stepy %d\n",rays->stepx, rays->stepy);
	printf("rays sidesdisx %f and sidedisy %f\n",rays->side_dist_x, rays->side_dist_y);
	printf("rays mapx %d and mapy %d\n",rays->mapx, rays->mapy);
	printf("rays dirx %f and diry %f\n",rays->diry, rays->diry);
	printf(" ray angle %f\n",rays->r_angle);
}
